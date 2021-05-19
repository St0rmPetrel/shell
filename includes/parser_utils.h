/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:29:12 by serma             #+#    #+#             */
/*   Updated: 2021/04/13 14:17:58 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "libft.h"
# include "command.h"

int			is_pipe(char *str);
int			is_semicolon(char *str);
int			is_out_rd(char *str);
int			is_out_append_rd(char *str);
int			is_in_rd(char *str);

int			count_of_cmds(char **proc_str);
int			count_of_sim_cmds(char **proc_str);
int			count_of_arg(char **proc_str);
char		**give_next_cmd(char **proc_str);
char		**give_next_smpl_cmd(char **proc_str);
t_smpl_cmd	*fill_false_smpl_cmnd(void);

#endif
