/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:23:32 by prautha           #+#    #+#             */
/*   Updated: 2021/04/09 18:53:49 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "programm_utils.h"

char	*add_symbol(char *str, char symbol)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(str) + 2);
	if (!new_str)
		error_exit_message("Error malloc.", errno);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = symbol;
	new_str[i] = '\0';
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (new_str);
}
