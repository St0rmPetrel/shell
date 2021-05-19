/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:45:00 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 18:30:32 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "programm_utils.h"

char	*give_env_var(char *var, char **envp)
{
	char	*content;
	char	**env_ptr;

	if ((!var) || (!envp))
		return (0);
	env_ptr = give_env_varptr(var, envp);
	if (!env_ptr)
		return (0);
	content = ft_strchr(*env_ptr, '=');
	if (content)
		return (content + 1);
	return (0);
}

static int	is_varinstr(char *str, char *var)
{
	int		var_len;
	int		pre_len;
	char	*eqv_sign;

	eqv_sign = ft_strchr(str, '=');
	if (!eqv_sign)
		return (!ft_strcmp(var, str));
	pre_len = (int)(eqv_sign - str);
	var_len = ft_strlen(var);
	if (pre_len != var_len)
		return (0);
	return (!ft_strncmp(var, str, var_len));
}

char	**give_env_varptr(char *var, char **envp)
{
	int		i;

	if ((!var) || (!envp))
		return (0);
	i = 0;
	while (envp[i])
	{
		if (is_varinstr(envp[i], var))
			return (envp + i);
		i++;
	}
	return (0);
}

int	is_valid_var_name(char *var)
{
	size_t	i;

	if (!(ft_isalpha(*var) || (*var == '_')))
		return (0);
	i = 1;
	while (var[i])
	{
		if (!(ft_isalnum(var[i]) || (var[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

int	change_var_val(char *var, char *new_val, char **envp)
{
	char	**env_ptr;
	char	*dup_new_val;

	env_ptr = give_env_varptr(var, envp);
	if (!env_ptr)
		return (1);
	dup_new_val = ft_strdup(var);
	if (!dup_new_val)
		error_exit_message("", errno);
	dup_new_val = ft_strjoin_free(dup_new_val, "=");
	dup_new_val = ft_strjoin_free(dup_new_val, new_val);
	free(*env_ptr);
	*env_ptr = dup_new_val;
	return (0);
}
