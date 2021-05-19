/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:11:12 by serma             #+#    #+#             */
/*   Updated: 2021/03/24 12:18:04 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	counter;
	int		ret;

	counter = 0;
	ret = 0;
	while ((s1[counter] != '\0') && (s2[counter] != '\0'))
	{
		ret = (unsigned char)s1[counter] - (unsigned char)s2[counter];
		if (ret != 0)
			return (ret);
		counter++;
	}
	ret = (unsigned char)s1[counter] - (unsigned char)s2[counter];
	return (ret);
}
