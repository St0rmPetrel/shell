/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:45:24 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 11:38:18 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
		len = 0;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
