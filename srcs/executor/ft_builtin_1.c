/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:32:01 by telman            #+#    #+#             */
/*   Updated: 2021/04/15 22:23:37 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "builtin.h"
#include "programm_utils.h"
#include "libft.h"

int	ft_exit(char **argv, t_data *state)
{
	int		argc;

	argc = arr_size((const char **)argv);
	if (argc <= 1)
		exit(state->status);
	if (!ft_isnumber(argv[1]))
	{
		error_message("exit: numeric argument required", 0);
		exit(2);
	}
	if (argc > 2)
		error_message("exit: too many arguments", 0);
	if (argc == 2)
		exit(ft_atoi(argv[1]));
	return (1);
}

int	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) == 0)
	{
		error_message("pwd: ", errno);
		return (errno);
	}
	printf("%s\n", cwd);
	return (0);
}

int	ft_false(void)
{
	return (1);
}

int	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '='))
			printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

int	ft_echo(char **argv)
{
	int	argc;
	int	is_new_line;
	int	i;

	argc = arr_size((const char **)argv);
	is_new_line = 1;
	i = 1;
	if ((argc >= 2) && (!ft_strcmp(argv[1], "-n")))
	{
		is_new_line = 0;
		i++;
	}
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		if (i < argc)
			write(1, " ", 1);
	}
	if (is_new_line)
		write(1, "\n", 1);
	return (0);
}
