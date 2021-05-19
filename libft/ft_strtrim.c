/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:13:22 by prautha           #+#    #+#             */
/*   Updated: 2020/11/07 22:01:59 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*arr;
	size_t		i;
	size_t		n;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	n = ft_strlen(s1);
	if (n == i)
		return (ft_strdup(""));
	while (s1[n - 1] && ft_strchr(set, s1[n - 1]))
		n--;
	arr = ft_substr(s1, i, (n - i));
	return (arr);
}
