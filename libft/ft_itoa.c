/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:07:43 by prautha           #+#    #+#             */
/*   Updated: 2020/11/06 23:33:29 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_chr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			var[2];
	long		m;

	m = (long)n;
	var[0] = ft_quantity_chr(m);
	var[1] = var[0];
	arr = (char *)malloc(var[0] + 1);
	if (!arr)
		return (NULL);
	var[0] = 0;
	if (m < 0)
	{
		arr[var[0]++] = '-';
		m *= -1;
	}
	arr[var[1]] = '\0';
	while (--var[1] >= var[0])
	{
		arr[var[1]] = (m % 10) + 48;
		m = m / 10;
	}
	return (arr);
}
