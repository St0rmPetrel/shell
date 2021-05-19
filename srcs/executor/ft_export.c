/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:47:46 by telman            #+#    #+#             */
/*   Updated: 2021/04/15 18:49:03 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "programm_utils.h"
#include "builtin_utils.h"
#include "data.h"

static void	show_export(char **envp)
{
	int		i;
	char	*str;

	i = 0;
	if (!envp)
		return ;
	arr_sort(envp);
	while (envp[i])
	{
		str = create_str(envp[i]);
		printf("%s\n", str);
		free(str);
		i++;
	}
}

static void	change_str(char **env_ptr, char *new)
{
	if (ft_strchr(*env_ptr, '=') && !ft_strchr(new, '='))
		return ;
	free(*env_ptr);
	*env_ptr = new;
}

static int	inner_export(char *new_env_var, t_data *state)
{
	char	*var;
	char	**env_ptr;

	var = cut_var(new_env_var);
	if (!is_valid_var_name(var))
	{
		free(var);
		return (1);
	}
	env_ptr = give_env_varptr(var, state->env);
	if (env_ptr)
		change_str(env_ptr, ft_strdup_save(new_env_var));
	else
		ft_arradd(&(state->env), ft_strdup_save(new_env_var));
	free(var);
	return (0);
}

int	ft_export(char **argv, t_data *state)
{
	size_t	argc;
	size_t	i;
	int		ret;
	char	*var;

	argc = arr_size((const char **)argv);
	if (argc == 1)
		show_export(state->env);
	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (inner_export(argv[i], state))
		{
			ret = 1;
			var = cut_var(argv[i]);
			builtin_error_message(argv[0], var, "not a valid identifier");
			free(var);
		}
		i++;
	}
	return (ret);
}
