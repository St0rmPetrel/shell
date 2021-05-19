/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaction_on_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:52:01 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:41:11 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int	reaction_on_signal(t_history *history)
{
	if (ctrl_d_response(history))
		return (1);
	else
		history->ctrl_d = 1;
	return (0);
}

int	reaction_on_input(t_data *data, char *buff,
						t_history *history, struct termios *save_term)
{
	if (!ft_strcmp(buff, CTRL_D))
		return (reaction_on_signal(history));
	if (!ft_strcmp(buff, UP))
		up_response(data, history);
	if (!ft_strcmp(buff, DOWN))
		down_response(data, history);
	if (!ft_strcmp(buff, RIGHT))
		return (1);
	if (!ft_strcmp(buff, LEFT))
		return (1);
	if (!ft_strcmp(buff, BACKSPACE))
		backspace_response(data, history, save_term);
	if (!ft_strcmp(buff, TAB))
		return (1);
	return (1);
}
