/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:28:34 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 11:40:13 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int			i;
	char		*tmp;
	char		*arr;

	arr = (char *)str;
	tmp = NULL;
	i = 0;
	if (str[0] == '\0' && ch == '\0')
	{
		tmp = &arr[0];
		return (tmp);
	}
	while (arr[i])
	{
		if (arr[i] == (char)ch)
			tmp = &arr[i];
		if (arr[i + 1] == '\0' && (char)ch == '\0')
			tmp = &arr[i + 1];
		i++;
	}
	if (tmp)
		return (tmp);
	return (NULL);
}
