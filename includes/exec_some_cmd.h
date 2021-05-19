/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_some_cmd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:38:02 by telman            #+#    #+#             */
/*   Updated: 2021/03/26 11:38:03 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_SOME_CMD_H
# define EXEC_SOME_CMD_H

# include "data.h"

int	exec_some_cmd(char **argv, t_data *state);
int	exec_bin(char *path, char **argv, t_data *state);
int	exec_builtin(char **argv, t_data *state);

#endif
