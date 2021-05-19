/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:38:19 by telman            #+#    #+#             */
/*   Updated: 2021/04/08 18:26:08 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"

int	ft_echo(char **argv);
int	ft_pwd(void);
int	ft_false(void);
int	ft_env(char **envp);
int	ft_exit(char **argv, t_data *state);
int	ft_export(char **argv, t_data *state);
int	ft_unset(char **argv, t_data *state);
int	ft_cd(char **argv, t_data *state);

#endif
