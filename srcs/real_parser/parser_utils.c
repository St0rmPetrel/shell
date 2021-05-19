/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:27:02 by serma             #+#    #+#             */
/*   Updated: 2021/04/13 14:01:56 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_parser.h"
#include "parser_utils.h"

int	count_of_cmds(char **proc_str)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	while (proc_str[i])
	{
		if (is_semicolon(proc_str[i]))
			ret++;
		i++;
	}
	return (ret);
}

int	count_of_sim_cmds(char **proc_str)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	while ((proc_str[i]) && !is_semicolon(proc_str[i]))
	{
		if (is_pipe(proc_str[i]))
			ret++;
		i++;
	}
	return (ret);
}

int	count_of_arg(char **proc_str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while ((proc_str[i]) && !is_semicolon(proc_str[i]) && (
			!is_pipe(proc_str[i])))
	{
		if (is_out_rd(proc_str[i]) || is_out_append_rd(proc_str[i]) || (
				is_in_rd(proc_str[i])))
			i++;
		else
			ret++;
		i++;
	}
	return (ret);
}

char	**give_next_cmd(char **proc_str)
{
	int	i;

	i = 0;
	while ((proc_str[i]) && !is_semicolon(proc_str[i]))
		i++;
	if (proc_str[i] && is_semicolon(proc_str[i]))
		i++;
	return (proc_str + i);
}

char	**give_next_smpl_cmd(char **proc_str)
{
	int	i;

	i = 0;
	while ((proc_str[i]) && !is_pipe(proc_str[i]) && (
			!is_semicolon(proc_str[i])))
		i++;
	if (proc_str[i] && is_pipe(proc_str[i]))
		i++;
	return (proc_str + i);
}
