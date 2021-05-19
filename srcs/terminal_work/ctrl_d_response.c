/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:45:09 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:59:20 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	ctrl_d_response(t_history *history)
{
	if (ft_strlen(history->act_str))
	{
		tputs(tgoto(tgetstr("ch", 0), 0, (
					ft_strlen(history->act_str) + 12)), 1, ft_putint);
		return (1);
	}
	tputs(tgoto(tgetstr("ch", 0), 0, 0), 1, ft_putint);
	tputs(tgetstr("dl", 0), 1, ft_putint);
	ft_putstr_fd("\e[1;35mMade by Dva_deda team.\n\e[0m", STDOUT_FILENO);
	ft_putstr_fd("\e[1;35mContact us again!\n\e[0m", STDOUT_FILENO);
	ft_putstr_fd("\e[1;35mBye!\n\e[0m", STDOUT_FILENO);
	return (0);
}
