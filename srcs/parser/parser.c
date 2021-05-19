/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:01:17 by prautha           #+#    #+#             */
/*   Updated: 2021/04/15 15:25:00 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**parser_env(char **env)
{
	short		i;
	int			q_str;
	char		**our_env;

	q_str = ft_strlen_arr(env);
	our_env = (char **)malloc((q_str + 1) * sizeof(char *));
	if (!our_env)
		error_exit_message("Error malloc.", errno);
	i = -1;
	while (++i < q_str)
	{
		our_env[i] = ft_strdup(env[i]);
		if (!our_env[i])
			error_exit_message("Error malloc.", errno);
	}
	our_env[i] = NULL;
	return (our_env);
}

t_smpl_cmd	***parser(t_data *data, char **env)
{
	struct termios	*save_term;
	char			*actual_line;
	short			signal;
	t_smpl_cmd		***all_comd;

	if (!isatty(STDIN_FILENO))
		error_exit_message("FD 0 not a terminal.\n", errno);
	if (data->env == NULL)
		data->env = parser_env(env);
	save_term = ft_calloc(1, sizeof(struct termios));
	tcgetattr(STDIN_FILENO, save_term);
	signal = 0;
	actual_line = term_work(data, &signal, save_term);
	restore_term(save_term, NULL);
	if (signal)
		return (NULL);
	if (!actual_line)
		ctrl_d(data);
	all_comd = create_arr_all_comd(data, actual_line);
	if (!all_comd)
		return (NULL);
	return (all_comd);
}
