/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_proccesing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:28:53 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 13:51:25 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*extract_var(char **env, char *arg, char *str)
{
	int		i;
	int		j;

	str = add_symbol(str, '=');
	i = 0;
	j = ft_strlen(str);
	while (env[i])
	{
		if (!(ft_strncmp(str, env[i], j)))
			break ;
		i++;
	}
	if (env[i] == NULL)
	{
		free(str);
		return (arg);
	}
	arg = ft_strjoin_free(arg, &env[i][j]);
	free(str);
	return (arg);
}

static char	*path_proccesing_other(t_parser *parser, char **env, char *arg)
{
	char	*str;

	str = NULL;
	str = ft_strdup("");
	if (!str)
		error_exit_message("Error malloc.", errno);
	while (parser->line[parser->i] && (parser->line[parser->i] != ' '
		) && !(ft_strchr(";'\"<>|$\\", parser->line[parser->i])))
	{
		str = add_symbol(str, parser->line[parser->i]);
		parser->i++;
	}
	arg = extract_var(env, arg, str);
	return (arg);
}

char	*path_proccesing(t_parser *parser, char **env, char *arg)
{
	parser->i++;
	if (parser->line[parser->i] == '\0')
		arg = add_symbol(arg, '$');
	else if (parser->line[parser->i] == '?')
	{
		arg = ft_strjoin_free(arg, parser->status);
		parser->i++;
		return (arg);
	}
	else
		arg = path_proccesing_other(parser, env, arg);
	return (arg);
}
