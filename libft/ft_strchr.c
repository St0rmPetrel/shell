/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:14:17 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 12:03:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int			i;
	char		*arr;

	i = 0;
	arr = (char *)str;
	while (arr[i])
	{
		if (arr[i] == (char)ch)
			return (&arr[i]);
		if (arr[i + 1] == (char)ch)
			return (&arr[i + 1]);
		i++;
	}
	if (ch == '\0')
		return (&arr[i]);
	return (NULL);
}
