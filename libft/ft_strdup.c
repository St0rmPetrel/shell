/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:05:26 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 11:53:08 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*arr;
	int		i;
	int		j;

	i = ft_strlen(src);
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		arr[j] = src[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
