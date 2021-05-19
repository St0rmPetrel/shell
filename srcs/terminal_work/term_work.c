/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:50:57 by prautha           #+#    #+#             */
/*   Updated: 2021/04/15 16:14:47 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	init_term(struct termios *mini_term, struct termios *save_term)
{
	char		*termtype;

	tcgetattr(STDIN_FILENO, mini_term);
	mini_term->c_lflag &= ~(ICANON | ECHO);
	mini_term->c_cc[VMIN] = 0;
	mini_term->c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, mini_term);
	termtype = getenv("TERM");
	if (termtype == NULL || tgetent(0, termtype) != 1)
		restore_term(save_term, "Can not find terminal or termcap base. \
		Please, choose one and define the \"TERM\" variable");
}

static char	*signal_work(t_data *data, t_history *history, short *signal)
{
	if (history->ctrl_c)
	{
		*signal = 1;
		data->history = ft_duo_lstfirst(data->history);
	}
	if (history->ctrl_d)
	{
		if (history->tmp_str)
			free(history->tmp_str);
		*signal = 0;
	}
	free(history);
	return (NULL);
}

static char	*empty_str_reaction(t_data *data, t_history *history, short *signal)
{
	if (history->act_str)
	{
		free(history->act_str);
		history->act_str = NULL;
	}
	free(history);
	history = NULL;
	*signal = 1;
	data->history = ft_duo_lstfirst(data->history);
	return (NULL);
}

char	*term_work(t_data *data, short *signal,
					struct termios *save_term)
{
	struct termios	mini_term;
	t_history		*history;

	init_term(&mini_term, save_term);
	history = ft_calloc(1, sizeof(t_history));
	ft_putstr_fd("\e[1;35mminishell ► \e[0m", STDOUT_FILENO);
	tputs(tgetstr("sc", 0), 1, ft_putint);
	if (!(receive_str(data, history, save_term)))
		return (signal_work(data, history, signal));
	if (ft_strlen(history->act_str) == 0)
		return (empty_str_reaction(data, history, signal));
	if (!(ft_duo_lstadd_front(&data->history, ft_duo_lstnew(history->act_str))))
		restore_term(save_term, "Error malloc.");
	if (history)
		free(history);
	return ((char *)data->history->content);
}
