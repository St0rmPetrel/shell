/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_some_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:33:13 by telman            #+#    #+#             */
/*   Updated: 2021/04/16 14:39:54 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec_some_cmd.h"
#include "programm_utils.h"
#include "search_in_path.h"

static int	is_builtin(char *cmd_name)
{
	if (!ft_strcmp(cmd_name, "echo"))
		return (1);
	if (!ft_strcmp(cmd_name, "cd"))
		return (1);
	if (!ft_strcmp(cmd_name, "pwd"))
		return (1);
	if (!ft_strcmp(cmd_name, "export"))
		return (1);
	if (!ft_strcmp(cmd_name, "unset"))
		return (1);
	if (!ft_strcmp(cmd_name, "env"))
		return (1);
	if (!ft_strcmp(cmd_name, "exit"))
		return (1);
	if (!ft_strcmp(cmd_name, "false"))
		return (1);
	return (0);
}

static int	is_path(char *cmd_name)
{
	if ((cmd_name[0] == '.') || (cmd_name[0] == '/'))
		return (1);
	return (0);
}

int	exec_some_cmd(char **argv, t_data *state)
{
	char	*path;
	char	*msg;
	int		status;

	if (!argv[0])
		return (0);
	if (is_path(argv[0]))
		return (exec_bin(argv[0], argv, state));
	if (is_builtin(argv[0]))
		return (exec_builtin(argv, state));
	path = search_in_path(argv[0], state->env);
	if (!path)
	{
		msg = ft_strjoin(argv[0], ": command not found");
		error_message(msg, 0);
		free(msg);
		return (127);
	}
	status = exec_bin(path, argv, state);
	free(path);
	return (status);
}
