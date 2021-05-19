/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:04:53 by telman            #+#    #+#             */
/*   Updated: 2021/03/31 11:14:44 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	if (((*str == '-') || (*str == '+')) && (str[1] != 0))
		counter++;
	while (str[counter])
	{
		if (!ft_isdigit(str[counter]))
			return (0);
		counter++;
	}
	return (1);
}
