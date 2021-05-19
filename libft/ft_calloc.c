/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:03:52 by prautha           #+#    #+#             */
/*   Updated: 2020/11/06 16:58:00 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*arr;

	arr = (size_t *)malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, (nmemb * size));
	return (arr);
}
