#include "mini_serv.h"

// ./mini PORT 
//! Memory or fd leaks are forbidden

//* if system call fail before accepting -> write(2, "Fatal error\n", strlen("Fatal error") + 1) and exit(1)
//* if can't allocate memo -> write(2, "Fatal error\n", strlen("Fatal error") + 1) and exit(1)
//* if new client is connected to server ; broadcast -> "server: client ID just arrived\n"
//? New line '\n' is the separator
//* when server recieve a client's message ; broadcast -> "client ID : ....MSG LINE...."
//* when client is disconnected ; broadcast -> "server: client ID just left\n"

void error_fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error") + 1);
	exit(1);
}

int	setOptionSocket(int fd)
{
	int	optval = 1;

	//?-	Reusable addresss
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)))
		return 1;
	//?-	Non Blocking fd
	if (fcntl(fd, F_SETFL,	O_NONBLOCK) < 0)
		return 1;
	return 0;
}

void broadcastMessage(vector *clients, char *msg)
{
	// boradcast msg to all client in the clients vector.
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments") + 1);
		exit(1);
	}

	int serv_socket;
	int port;
	struct sockaddr_in addr;

	port = atoi(av[1]);
	printf("Port : %d\n", port);
	serv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv_socket < 0)
		error_fatal();
	if (setOptionSocket(serv_socket))
		error_fatal();

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(serv_socket, (struct sockaddr *)&addr, (socklen_t)sizeof(addr)))
		error_fatal();

	if (listen(serv_socket, SOMAXCONN))
		error_fatal();

	printf("Server \n");

	while (1)
	{
		
	}

	close(serv_socket);

}
