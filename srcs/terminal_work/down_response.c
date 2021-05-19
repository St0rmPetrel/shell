/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_response.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:48:20 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:56:44 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	down_response_other(t_history *history)
{
	tputs(tgoto(tgetstr("ch", 0), 0, 12), 1, ft_putint);
	history->flag = 0;
}

static void	history_null(t_history *history)
{
	tputs(tgoto(tgetstr("ch", 0), 0, (
				ft_strlen(history->act_str) + 12)), 1, ft_putint);
	history->flag = 0;
}

static void	restore_cursore(void)
{
	tputs(tgetstr("rc", 0), 1, ft_putint);
	tputs(tgetstr("ce", 0), 1, ft_putint);
}

void	down_response(t_data *data, t_history *history)
{
	if (data->history == NULL)
		history_null(history);
	else
	{
		if (history->tmp_h_str)
		{
			free(history->tmp_h_str);
			history->tmp_h_str = NULL;
		}
		restore_cursore();
		if (data->history->prev)
		{
			history->act_str = data->history->prev->content;
			write(STDOUT_FILENO, history->act_str, ft_strlen(history->act_str));
			data->history = data->history->prev;
			history->flag = 1;
			return ;
		}
		else
			down_response_other(history);
	}
	history->act_str = history->tmp_str;
	restore_cursore();
	write(STDOUT_FILENO, history->act_str, ft_strlen(history->act_str));
}
