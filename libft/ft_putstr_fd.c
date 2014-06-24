/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:20:31 by bcrespin          #+#    #+#             */
/*   Updated: 2014/02/04 15:27:31 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		fd = 0;
	if (fd)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
}