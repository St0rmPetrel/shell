/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_str_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:23:16 by prautha           #+#    #+#             */
/*   Updated: 2021/04/15 21:23:18 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	cmp_history(t_data *data, char *str)
{
	t_duo_list	*tmp;

	tmp = data->history;
	tmp = ft_duo_lstfirst(tmp);
	while (tmp)
	{
		if (str == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_comd(char *buff)
{
	if (!ft_strcmp(buff, CTRL_D) || !ft_strcmp(buff, UP) || !ft_strcmp(
			buff, DOWN) || !ft_strcmp(buff, RIGHT) || !ft_strcmp(
			buff, LEFT) || !ft_strcmp(buff, BACKSPACE) || !ft_strcmp(
			buff, TAB))
	{
		return (1);
	}
	return (0);
}
