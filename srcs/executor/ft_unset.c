/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:10:25 by telman            #+#    #+#             */
/*   Updated: 2021/04/12 13:24:06 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "programm_utils.h"
#include "data.h"

static void	erase_var(char ***envp, char *var)
{
	char	**env_ptr;
	char	**new_envp;

	env_ptr = give_env_varptr(var, *envp);
	if (!env_ptr)
		return ;
	free(*env_ptr);
	ft_arrcpy(env_ptr, (const char **)(env_ptr + 1));
	new_envp = ft_arrdup((const char **)*envp);
	free_arr(*envp);
	*envp = new_envp;
}

int	ft_unset(char **argv, t_data *state)
{
	int		ret;
	size_t	argc;
	size_t	i;

	argc = arr_size((const char **)argv);
	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_var_name(argv[i]))
		{
			builtin_error_message(argv[0], argv[i], "not a valid identifier");
			ret = 1;
			i++;
			continue ;
		}
		erase_var(&(state->env), argv[i]);
		i++;
	}
	return (ret);
}
