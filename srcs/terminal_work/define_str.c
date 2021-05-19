/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:43:36 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 13:45:01 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	str_not_history(t_history *history, struct termios *s_t, char *buff)
{
	history->tmp_str = add_symbol(history->tmp_str, buff[0]);
	if (!history->tmp_str)
		restore_term(s_t, "Error malloc.");
	history->act_str = history->tmp_str;
}

static void	str_is_history(t_history *history, struct termios *s_t, char *buff)
{
	history->act_str = ft_strdup(history->act_str);
	history->act_str = add_symbol(history->act_str, buff[0]);
	if (!history->act_str)
		restore_term(s_t, "Error malloc.");
	if (history->tmp_h_str)
	{
		free(history->tmp_h_str);
		history->tmp_h_str = NULL;
	}
	history->tmp_h_str = history->act_str;
}

void	define_str(t_history *history, char	*buff, struct termios *s_t)
{
	if (history->flag == 1)
		str_is_history(history, s_t, buff);
	else
		str_not_history(history, s_t, buff);
}
