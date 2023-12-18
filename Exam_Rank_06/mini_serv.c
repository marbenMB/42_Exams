#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <libc.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void	error(char *msg, int stat)
{
	write(2, msg, strlen(msg));
	exit (stat);
}

int fds[700000], max_fd, fds_count = 0;
char *msgs[700000];
char noitfmsg[42];
char buffer[1024];
fd_set readfds, writefds, global;

void	notification(int fd, char *msg)
{
	for (int i = 0; i < max_fd + 1; i++)
	{
		if (FD_ISSET(i, &global) && i != fd)
			send(i, msg, strlen(msg), 0);
	}
}

void	add_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	fds[fd] = fds_count++;
	msgs[fd] = NULL;
	FD_SET(fd, &global);
	sprintf(noitfmsg, "server: client %d just arrived\n", fds[fd]);
	notification(fd, noitfmsg);
}

void	rm_client(int fd)
{
	sprintf(noitfmsg, "server: client %d just left\n", fds[fd]);
	notification(fd, noitfmsg);
	FD_CLR(fd, &global);
	close(fd);
	if (msgs[fd] != NULL)
		free(msgs[fd]);
	msgs[fd] = NULL;
}

void	send_message(int fd)
{
	char *msg;
	while (extract_message(&msgs[fd], &msg))
	{
		sprintf(noitfmsg, "client %d: ", fds[fd]);
		notification(fd, noitfmsg);
		notification(fd, msg);
		free(msg);
	}
}

int main(int ac, char **av) {
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cliaddr; 

	if (ac != 2)
		error("Wrong number of arguments\n", 1);

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) error("Fatal error\n", 1); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) error("Fatal error\n", 1); 
	if (listen(sockfd, 10) != 0) error("Fatal error\n", 1); 
	
	FD_ZERO(&global);
	FD_SET(sockfd, &global);
	max_fd = sockfd;

	while (1)
	{
		writefds = readfds = global;

		if (select(max_fd + 1, &readfds, &writefds, NULL, 0) < 0) error("Fatal error\n", 1); 
		for (int i = 0; i < max_fd + 1; i++)
		{
			if (FD_ISSET(i, &readfds))
			{
				if (i == sockfd)
				{
					len = sizeof(cliaddr);
					connfd = accept(i, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
					if (connfd < 0) 
						return (0);
					add_client(connfd);
					break;
				}
				else
				{
					int n = recv(i, buffer, 1000, 0);
					if (n <= 0)
						rm_client(i);
					else
					{
						buffer[n] = 0;
						msgs[i] = str_join(msgs[i], buffer);
						send_message(i);
					}
					break;
				}
			}
		}
	}
}