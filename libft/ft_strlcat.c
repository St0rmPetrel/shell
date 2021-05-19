/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:36:28 by prautha           #+#    #+#             */
/*   Updated: 2020/11/07 19:01:33 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	l;

	i = ft_strlen(dest);
	if (src[0] == 0)
		return (i);
	l = 0;
	if (i < size)
	{
		while (l < size - i - 1 && src[l])
		{
			dest[l + i] = src[l];
			l++;
		}
	}
	else
		return (ft_strlen(src) + size);
	dest[l + i] = '\0';
	return (ft_strlen(src) + i);
}
