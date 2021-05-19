/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:23:54 by prautha           #+#    #+#             */
/*   Updated: 2020/11/06 15:53:17 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	if (!(dest || src))
		return (0);
	d = ft_strlen(src);
	s = ft_strlen(src);
	if (size == 0)
		return (s);
	i = -1;
	if (d >= s)
	{
		while (++i < s && i < size - 1 && src[i] != '\0')
			dest[i] = src[i];
		if (i < size)
			dest[i] = '\0';
		return (s);
	}
	while (++i < d && i < size - 1)
		dest[i] = src[i];
	if (i < size)
		dest[i] = '\0';
	return (s);
}
