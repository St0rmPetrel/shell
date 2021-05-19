/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:38:58 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 11:40:54 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		l;
	char		*arr;
	char		*tmp;

	arr = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return (arr);
	while (i < len && arr[i])
	{
		if (arr[i] == little[0])
		{
			tmp = &arr[i];
			l = 1;
			while (little[l] && arr[i + l] == little[l] && (i + l) < len)
				l++;
			if (little[l] == '\0')
				return (tmp);
		}
		i++;
	}
	return (NULL);
}
