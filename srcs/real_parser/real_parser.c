/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:13:22 by serma             #+#    #+#             */
/*   Updated: 2021/04/15 16:10:33 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "real_parser.h"
#include "programm_utils.h"
#include "parser_utils.h"
#include "proc_redirect.h"

static int	is_end_smpl_cmd(char *str)
{
	if (!str || is_pipe(str) || is_semicolon(str))
		return (1);
	return (0);
}

static t_smpl_cmd	*create_smpl_cmd(char **proc_str)
{
	int			arg_num;
	t_smpl_cmd	*ret;

	ret = ft_calloc(1, sizeof(t_smpl_cmd));
	if (!ret)
		error_exit_message("", errno);
	arg_num = count_of_arg(proc_str);
	ret->argv = ft_calloc(arg_num + 1, sizeof(char *));
	if (!(ret->argv))
		error_exit_message("", errno);
	return (ret);
}

t_smpl_cmd	*fill_smpl_cmd(char **proc_str)
{
	t_smpl_cmd	*ret;
	int			i;

	ret = create_smpl_cmd(proc_str);
	i = 0;
	while (!is_end_smpl_cmd(*proc_str))
	{
		if (is_out_rd(*proc_str) || is_out_append_rd(*proc_str) || (
				is_in_rd(*proc_str)))
		{
			if (proc_redirect(ret, &proc_str))
			{
				free_smpl_cmd(ret);
				return (0);
			}
		}
		else
		{
			(ret->argv)[i] = ft_strdup_save(*proc_str);
			proc_str++;
			i++;
		}
	}
	return (ret);
}

t_smpl_cmd	**fill_cmnd(char **proc_str)
{
	t_smpl_cmd	**ret;
	int			smpl_cmd_num;
	int			i;

	smpl_cmd_num = count_of_sim_cmds(proc_str);
	ret = ft_calloc(smpl_cmd_num + 1, sizeof(t_smpl_cmd *));
	if (!ret)
		error_exit_message("", errno);
	i = 0;
	while (*proc_str && !is_semicolon(*proc_str))
	{
		ret[i] = fill_smpl_cmd(proc_str);
		if (!ret[i])
			ret[i] = fill_false_smpl_cmnd();
		proc_str = give_next_smpl_cmd(proc_str);
		i++;
	}
	return (ret);
}

t_smpl_cmd	***real_parser(char **proc_str)
{
	t_smpl_cmd	***ret;
	int			cmds_num;
	int			i;

	if ((!proc_str) || (!*proc_str))
		return (0);
	cmds_num = count_of_cmds(proc_str);
	ret = ft_calloc(cmds_num + 1, sizeof(t_smpl_cmd **));
	if (!ret)
		error_exit_message("", errno);
	i = 0;
	while (*proc_str)
	{
		ret[i] = fill_cmnd(proc_str);
		proc_str = give_next_cmd(proc_str);
		i++;
	}
	return (ret);
}
