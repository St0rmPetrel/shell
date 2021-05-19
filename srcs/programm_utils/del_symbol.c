/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:49:23 by prautha           #+#    #+#             */
/*   Updated: 2021/04/09 18:54:44 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "programm_utils.h"

char	*del_symbol(char *str)
{
	int		i;
	int		q;
	char	*new_str;

	q = ft_strlen(str);
	if (q == 0)
		return (str);
	new_str = (char *)malloc(q--);
	if (!new_str)
		error_exit_message("Error malloc.", errno);
	i = 0;
	while (i < q)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	if (str)
	{
		free(str);
		str = NULL;
	}
	str = NULL;
	return (new_str);
}
