/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:29 by telman            #+#    #+#             */
/*   Updated: 2021/04/15 16:10:26 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "programm_utils.h"
#include "command.h"

void	free_cmds(t_smpl_cmd ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		free_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_cmd(t_smpl_cmd **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free_smpl_cmd(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_smpl_cmd(t_smpl_cmd *smpl_cmd)
{
	free_arr(smpl_cmd->argv);
	free(smpl_cmd);
}
