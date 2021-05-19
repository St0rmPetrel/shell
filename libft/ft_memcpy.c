/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:15:53 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 13:04:38 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = 0;
	arr1 = (unsigned char *)dst;
	arr2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		arr1[i] = arr2[i];
		i++;
	}
	return (dst);
}
