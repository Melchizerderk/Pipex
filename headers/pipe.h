/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 17:34:17 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/17 16:05:58 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPE_H
# define PIPE_H

#include <unistd.h>
#include <libft.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/wait.h>

char	*ft_getpath(char **env);
char	*ft_searchpath(char *cmd, char **env);
void	ft_checkoutfile(char **av);
void	ft_dup_father(int *pfd, int fd);
void	ft_dup_child(int *pfd, int fd);
void	ft_checkinfile(char **av);
int		father_filecheck(char **av);

#endif
