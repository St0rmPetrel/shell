/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:41:10 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 18:58:35 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "data.h"

typedef struct s_smpl_cmd
{
	char	**argv;
	int		fd_in;
	int		fd_out;
}	t_smpl_cmd;

int		exec_command(t_smpl_cmd **command, t_data *state);
int		exec_group_commands(t_smpl_cmd ***cmds, t_data *state);

void	free_cmds(t_smpl_cmd ***cmds);
void	free_cmd(t_smpl_cmd **cmd);
void	free_smpl_cmd(t_smpl_cmd *smpl_cmd);

#endif
