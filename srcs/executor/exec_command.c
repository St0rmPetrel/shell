/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:48 by telman            #+#    #+#             */
/*   Updated: 2021/04/12 15:57:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "command.h"
#include "exec_some_cmd.h"

static void	rewrite_fd(int old, int new)
{
	dup2(old, new);
	close(old);
}

static int	exec_simple_cmd(t_smpl_cmd *simple_cmd, t_data *state)
{
	if (simple_cmd->fd_in)
		rewrite_fd(simple_cmd->fd_in, 0);
	if (simple_cmd->fd_out)
		rewrite_fd(simple_cmd->fd_out, 1);
	return (exec_some_cmd(simple_cmd->argv, state));
}

static int	simple_command_loop(t_smpl_cmd **cmd, t_data *state,
		int *tmp)
{
	int	i;
	int	fd[2];
	int	status;

	i = 0;
	fd[0] = dup(tmp[0]);
	while (cmd[i])
	{
		rewrite_fd(fd[0], 0);
		if (!cmd[i + 1])
			fd[1] = dup(tmp[1]);
		else
		{
			if (pipe(fd) < 0)
				return (1);
		}
		rewrite_fd(fd[1], 1);
		status = exec_simple_cmd(cmd[i], state);
		i++;
	}
	return (wait_all(state, status));
}

int	exec_command(t_smpl_cmd **command, t_data *state)
{
	int	tmp[2];
	int	ret;

	if (!command)
		return (1);
	tmp[0] = dup(0);
	tmp[1] = dup(1);
	ret = simple_command_loop(command, state, tmp);
	rewrite_fd(tmp[0], 0);
	rewrite_fd(tmp[1], 1);
	return (ret);
}

int	exec_group_commands(t_smpl_cmd ***cmds, t_data *state)
{
	int	i;
	int	status;

	i = 0;
	if ((!cmds) || (!state))
		return (1);
	while (cmds[i])
	{
		status = exec_command(cmds[i], state);
		i++;
	}
	return (status);
}
