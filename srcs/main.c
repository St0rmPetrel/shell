/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:02:13 by serma             #+#    #+#             */
/*   Updated: 2021/04/15 12:25:27 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "command.h"
#include "parser.h"
#include "data.h"
#include "builtin.h"

#include "real_parser.h"
#include "signal.h"

int	main(int argc, char **argv, char **env)
{
	t_smpl_cmd	***group_of_cmd;
	t_data		data;

	(void)argv;
	if (argc > 1)
		error_exit_message("Minishell works with no arguments.", errno);
	ft_bzero((void *)(&data), sizeof(data));
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_putstr_fd("\e[1;35mWelcome in our minishell !!!\n\e[0m", 1);
	while (WORK_PROGRAMM)
	{
		g_is_sigint = 0;
		group_of_cmd = parser(&data, env);
		if (group_of_cmd)
		{
			data.status = exec_group_commands(group_of_cmd, &data);
			free_cmds(group_of_cmd);
			group_of_cmd = 0;
		}
	}
	return (0);
}
