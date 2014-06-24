/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 17:33:42 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/14 19:16:25 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipe.h"

void	ft_fork(int pid, int *pfd, char **av, char **env)
{
	char	*path;
	char	**arg;
	int		fd;

	if (pid == 0)
	{
		fd = father_filecheck(av);
		ft_dup_father(pfd, fd);
		arg = ft_strsplit(av[3], ' ');
		path = ft_searchpath(av[3], env);
		if (execve(path, arg, 0) == -1)
			_exit(0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		ft_dup_child(pfd, fd);
		arg = ft_strsplit(av[2], ' ');
		path = ft_searchpath(av[2], env);
		if (execve(path, arg, 0) == -1)
			_exit(0);
	}
}

char	*ft_searchpath(char *cmd, char **env)
{
	char	*path;
	char	**tabpath;
	int		i;
	char	**try;

	i = 0;
	try = ft_strsplit(cmd, ' ');
	path = ft_getpath(env);
	tabpath = ft_strsplit(path, ':');
	while (tabpath[i])
	{
		tabpath[i] = ft_strjoin(tabpath[i], ft_strjoin("/", try[0]));
		if ((access(tabpath[i], X_OK)) == 0)
			return (tabpath[i]);
		else
			i++;
	}
	ft_putendl("Invalid function");
	return (0);
}

char	*ft_getpath(char **env)
{
	int		i;
	char	*fullpath;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "PWD=", 4) == 1)
			fullpath = ft_strdup(env[i] + 4);
		else if (ft_strnequ(env[i], "PATH=", 5) == 1)
			path = strdup(env[i] + 5);
		i++;
	}
	fullpath = ft_strjoin(fullpath, ft_strjoin(":", path));
	return (fullpath);
}

int		main(int ac, char **av, char **env)
{
	int		pid;
	int		pfd[2];

	if (ac == 5)
	{
		ft_checkoutfile(av);
		ft_checkinfile(av);
		if (pipe(pfd) == 0)
		{
			if ((pid = fork()) < 0)
			{
				ft_putendl("fork failed");
				return (0);
			}
			ft_fork(pid, pfd, av, env);
		}
		else
			ft_putendl("Pipe creation failed");
		return (0);
	}
	ft_putendl("Wrong number of argument");
	return (0);
}

void	ft_checkoutfile(char **av)
{
	if (access(av[4], F_OK) == -1)
		open(av[4], O_CREAT | O_RDWR);
}
