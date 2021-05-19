/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_response.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:49:50 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:26:42 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	up_response_work(t_data *data, t_history *history)
{
	t_duo_list	*pointer;

	if (history->tmp_h_str)
	{
		free(history->tmp_h_str);
		history->tmp_h_str = NULL;
	}
	tputs(tgetstr("rc", 0), 1, ft_putint);
	tputs(tgetstr("ce", 0), 1, ft_putint);
	pointer = data->history;
	if (pointer)
	{
		history->act_str = pointer->content;
		history->flag = 1;
		write(STDOUT_FILENO, history->act_str, ft_strlen(history->act_str));
		if (data->history->next)
			data->history = data->history->next;
	}
	else
	{
		tputs(tgetstr("rc", 0), 1, ft_putint);
		history->flag = 0;
	}
}

void	up_response(t_data *data, t_history *history)
{
	if (data->history == NULL)
	{
		tputs(tgoto(tgetstr("ch", 0), 0, (ft_strlen(history->act_str)
					+ 12)), 1, ft_putint);
		history->flag = 0;
	}
	else
		up_response_work(data, history);
}
