/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:36:47 by telman            #+#    #+#             */
/*   Updated: 2021/04/12 11:52:32 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "data.h"
#include "programm_utils.h"

static char	*give_cwd(void)
{
	char	cwd[4096];
	char	*ret;

	if (getcwd(cwd, sizeof(cwd)) == 0)
		error_exit_message("", errno);
	ret = ft_strdup(cwd);
	if (!ret)
		error_exit_message("", errno);
	return (ret);
}

static int	change_dir(char *path, char **envp)
{
	char	*old_path;
	char	*new_path;

	if (*path == '\0')
		return (0);
	old_path = give_cwd();
	if (chdir(path))
	{
		error_message("cd: ", errno);
		return (1);
	}
	if (give_env_varptr("OLDPWD", envp))
		change_var_val("OLDPWD", old_path, envp);
	free(old_path);
	new_path = give_cwd();
	if (give_env_varptr("PWD", envp))
		change_var_val("PWD", new_path, envp);
	free(new_path);
	return (0);
}

int	ft_cd(char **argv, t_data *state)
{
	int		argc;
	char	*path;

	argc = arr_size((const char **)argv);
	if (argc > 2)
	{
		error_message("cd: too many arguments", 0);
		return (1);
	}
	if (argc == 1)
		path = give_env_var("HOME", state->env);
	else
		path = argv[1];
	if (!path)
	{
		error_message("cd: HOME not set", 0);
		return (1);
	}
	return (change_dir(path, state->env));
}
