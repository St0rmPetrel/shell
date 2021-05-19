/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace_response.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:46:11 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 11:37:47 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	move_and_del(void)
{
	tputs(tgetstr("dc", 0), 1, ft_putint);
	tputs(tgetstr("le", 0), 1, ft_putint);
	tputs(tgetstr("dc", 0), 1, ft_putint);
}

static void	del_smb_reaction(t_history *history, struct termios *save_term)
{
	history->tmp_h_str = del_symbol(history->tmp_h_str);
	if (!history->tmp_h_str)
		restore_term(save_term, "Error malloc.");
	history->act_str = history->tmp_h_str;
}

void	backspace_response(t_data *data, t_history *history,
				struct termios *save_term)
{
	if (ft_strlen(history->act_str) == 0)
		return ;
	else
	{
		move_and_del();
		if (history->flag == 1)
		{
			if (cmp_history(data, history->act_str))
			{
				if (history->tmp_h_str)
					free(history->tmp_h_str);
				history->tmp_h_str = ft_strdup(history->act_str);
			}
			del_smb_reaction(history, save_term);
		}
		else
		{
			history->tmp_str = del_symbol(history->tmp_str);
			if (!history->tmp_str)
				restore_term(save_term, "Error malloc.");
			history->act_str = history->tmp_str;
		}
	}
}
