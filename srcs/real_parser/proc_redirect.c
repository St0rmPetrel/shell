/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:33:04 by serma             #+#    #+#             */
/*   Updated: 2021/04/13 14:02:51 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "programm_utils.h"
#include "parser_utils.h"
#include "proc_redirect.h"
#include "libft.h"

static int	proc_output(t_smpl_cmd *smpl_cmd, char *file_name)
{
	int		new_fd;

	new_fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 00664);
	if (new_fd < 0)
	{
		error_message(file_name, errno);
		return (1);
	}
	if (smpl_cmd->fd_out)
		close(smpl_cmd->fd_out);
	smpl_cmd->fd_out = new_fd;
	return (0);
}

static int	proc_out_append(t_smpl_cmd *smpl_cmd, char *file_name)
{
	int		new_fd;

	new_fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 00664);
	if (new_fd < 0)
	{
		error_message(file_name, errno);
		return (1);
	}
	if (smpl_cmd->fd_out)
		close(smpl_cmd->fd_out);
	smpl_cmd->fd_out = new_fd;
	return (0);
}

static int	proc_input(t_smpl_cmd *smpl_cmd, char *file_name)
{
	int		new_fd;

	new_fd = open(file_name, O_RDONLY);
	if (new_fd < 0)
	{
		error_message(file_name, errno);
		return (1);
	}
	if (smpl_cmd->fd_in)
		close(smpl_cmd->fd_in);
	smpl_cmd->fd_in = new_fd;
	return (0);
}

int	proc_redirect(t_smpl_cmd *smpl_cmd, char ***proc_str)
{
	if (is_out_rd(**proc_str))
	{
		(*proc_str)++;
		if (proc_output(smpl_cmd, **proc_str))
			return (1);
	}
	else if (is_out_append_rd(**proc_str))
	{
		(*proc_str)++;
		if (proc_out_append(smpl_cmd, **proc_str))
			return (1);
	}
	else if (is_in_rd(**proc_str))
	{
		(*proc_str)++;
		if (proc_input(smpl_cmd, **proc_str))
			return (1);
	}
	(*proc_str)++;
	return (0);
}
