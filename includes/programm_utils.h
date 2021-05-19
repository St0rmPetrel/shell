/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programm_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:05:13 by serma             #+#    #+#             */
/*   Updated: 2021/04/09 09:57:37 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAMM_UTILS_H
# define PROGRAMM_UTILS_H

# include <errno.h>
# include <stdlib.h>
# include "libft.h"

void	error_message(char *err_msg, int my_errno);
void	error_exit_message(char *err_msg, int my_errno);

void	free_arr(char **arr);
int		arr_size(const char **arr);
char	**ft_arrcpy(char **dest, const char **src);
char	**ft_arrdupcpy(char **dest, const char **src);
char	**ft_arrdup(const char **arr);
int		ft_arradd(char ***arr, char *new);
int		ft_arradd_back(char ***arr, char *new);
void	arr_sort(char **arr);

char	*give_env_var(char *var, char **envp);
char	**give_env_varptr(char *var, char **envp);
int		is_valid_var_name(char *var);
void	builtin_error_message(char *prog, char *arg, char *error_mes);
int		change_var_val(char *var, char *new_val, char **envp);

char	*quotes_take(char *str);
char	*ft_strjoin_free(char *a, char *b);
char	*ft_strdup_save(char *src);

char	*add_symbol(char *str, char symbol);
char	*del_symbol(char *str);

#endif
