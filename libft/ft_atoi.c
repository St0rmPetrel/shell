/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:44:06 by prautha           #+#    #+#             */
/*   Updated: 2020/11/09 17:56:28 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || (str[i] == '\n'
		) || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	long long	c;

	i = 0;
	j = 0;
	i = skip(str, i);
	if ((str[i] == 43 || str[i] == 45) && ((str[i + 1] >= 48
			) && str[i + 1] <= 57))
	{
		if (str[i++] == 45)
			j = 1;
	}
	c = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		c += str[i] - 48;
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			c *= 10;
		i++;
	}
	if (j == 1)
		c *= -1;
	return (c);
}
