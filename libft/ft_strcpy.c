/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:48:03 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:35:06 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1 && s2 && s2[i])
	{
		s1[i] = (char)s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
