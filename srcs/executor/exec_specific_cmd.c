/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_specific_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:32:27 by telman            #+#    #+#             */
/*   Updated: 2021/04/16 13:36:10 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "exec_some_cmd.h"
#include "programm_utils.h"
#include "builtin.h"

int	exec_bin(char *path, char **argv, t_data *state)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(path, argv, state->env);
		error_message(ft_strjoin(argv[0], ": "), errno);
		if (errno == 2)
			exit(127);
		exit(126);
	}
	else
		add_pid(pid, state);
	return (0);
}

int	exec_builtin(char **argv, t_data *state)
{
	char	*msg;

	if (!ft_strcmp(argv[0], "echo"))
		return (ft_echo(argv));
	if (!ft_strcmp(argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(argv[0], "env"))
		return (ft_env(state->env));
	if (!ft_strcmp(argv[0], "exit"))
		return (ft_exit(argv, state));
	if (!ft_strcmp(argv[0], "export"))
		return (ft_export(argv, state));
	if (!ft_strcmp(argv[0], "unset"))
		return (ft_unset(argv, state));
	if (!ft_strcmp(argv[0], "cd"))
		return (ft_cd(argv, state));
	if (!ft_strcmp(argv[0], "false"))
		return (ft_false());
	msg = ft_strjoin(argv[0], ": command not found");
	error_message(msg, 0);
	free(msg);
	return (127);
}
