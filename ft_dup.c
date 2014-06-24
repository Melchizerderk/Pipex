/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 19:44:11 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/14 19:17:42 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipe.h"

void	ft_dup_child(int *pfd, int fd)
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	close(pfd[1]);
	dup2(fd, 0);
}

void	ft_dup_father(int *pfd, int fd)
{
	close(pfd[1]);
	dup2(pfd[0], 0);
	close(pfd[0]);
	dup2(fd, 1);
}

void	ft_checkinfile(char **av)
{
	if (open(av[1], O_RDONLY) == -1)
	{
		ft_putendl("File doesn't exist, or you don't have read permission.");
		_exit(0);
	}
}

int		father_filecheck(char **av)
{
	int	fd;

	if ((fd = open(av[4], O_RDWR)) == -1)
	{
		ft_putendl("No read and write right on the output file.");
		_exit(0);
	}
	return (fd);
}
