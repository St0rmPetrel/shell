/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:53:05 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 12:10:57 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	ctrl_c_free(t_history *history)
{
	history->ctrl_c = 1;
	free(history->tmp_str);
	if (history->tmp_h_str)
	{
		free(history->tmp_h_str);
		history->tmp_h_str = NULL;
	}
}

static int	check_result(t_data *data, t_history *history)
{
	if (g_is_sigint == 1)
	{
		ctrl_c_free(history);
		return (0);
	}
	if (cmp_history(data, history->act_str))
	{
		history->act_str = ft_strdup(history->act_str);
		free(history->tmp_str);
		history->tmp_str = NULL;
		if (history->tmp_h_str)
		{
			free(history->tmp_h_str);
			history->tmp_h_str = NULL;
		}
	}
	else
	{
		if (history->flag)
		{
			free(history->tmp_str);
			history->tmp_str = NULL;
		}
	}
	return (1);
}

static void	create_str(t_history *history, char	*buff, struct termios *s_t)
{
	ft_memset(buff, 0, 2048);
	history->tmp_str = ft_strdup("");
	if (!history->tmp_str)
		restore_term(s_t, "Error malloc.");
	history->act_str = history->tmp_str;
}

static short	work_read(char	*buff, struct termios *save_term)
{
	short	status;

	ft_memset(buff, 0, 2048);
	status = read(STDIN_FILENO, buff, 2047);
	if (status == -1)
		restore_term(save_term, "Error function read. Exit.");
	return (status);
}

int	receive_str(t_data *data, t_history *history, struct termios *save_term)
{
	short		status;
	char		buff[2048];

	create_str(history, buff, save_term);
	while (ft_strcmp(buff, ENTER) && g_is_sigint == 0)
	{
		status = work_read(buff, save_term);
		if (buff[0] != '\0')
		{
			if (is_comd(buff))
			{
				if (!(reaction_on_input(data, buff, history, save_term)))
					return (0);
			}
			else
			{
				write(STDOUT_FILENO, buff, status);
				if (buff[0] == '\n')
					break ;
				define_str(history, buff, save_term);
			}
		}
	}
	return (check_result(data, history));
}
