/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:16:31 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/11/10 05:16:45 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>


int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ispipe(char **av)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (av[i])
	{
		if (!strcmp("|", av[i]))
		{
			ret = 1;
			av[i] = 0;
			break ;
		}
		if (!strcmp(";", av[i]))
		{
			ret = 0;
			av[i] = 0;
			break ;
		}
		i++;
	}
	return(ret);
}

int	ft_cd(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (-1);
	}
	if (chdir(av[1]) < 0)
	{
		write (2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
		write (2, av[1] , ft_strlen(av[1]));
		write (2, "\n", 1);
		return (-1);
	}
	return (0);
}

void	command_exe(int ac, char **av, char **env, int prev, int *fd_prev)
{
	int	next;
	int	fd_next[2];
	int	pid;
	int	exit_stat;
	int	i;

	if (ac <= 1)
		return ;
	next = ispipe(av);
	if (av[0])
	{
		if (next && pipe(fd_next) < 0)
		{
			write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
			exit (1);
		}
		if (!strcmp("cd", av[0]))
			ft_cd(av);
		else if ((pid = fork()) < 0)
		{
			write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
			exit (1);
		}
		else if (pid == 0)
		{
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit (-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit (-1);
			if (execve(av[0], av, env) < 0)
			{
				write (2, "error: cannot execute ", ft_strlen("error: cannot execute "));
				write (2, av[0], ft_strlen(av[0]));
				write (2, "\n", 1);
				exit (1);
			}
		}
		else 
		{
			if (waitpid(pid, &exit_stat, 0) < 0)
			{
				write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
				exit (1);
			}
			if (exit_stat / 256 == 255)
			{
				write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
				exit (1);
			}
			if (prev)
				close (fd_prev[0]);
			if (next)
				close (fd_next[1]);
		}
	}
	i = 0;
	while (av[i])
		i++;
	command_exe(ac - i - 1, av + i + 1, env, next, fd_next);
}

int main(int ac, char **av, char **env)
{
	int	prev;
	int	fd_prev[2];

	prev = 0;
	fd_prev[0] = 0;
	fd_prev[1] = 1;
	command_exe(ac, av + 1, env, prev, fd_prev);
	return (0);
}
