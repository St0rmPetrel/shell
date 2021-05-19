/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:26:09 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:02:42 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*parse_spec_smb_second(t_parser *parser, char **env, char *arg)
{
	if (parser->line[parser->i] == '\\')
		arg = shielding_proccesing(parser, arg);
	if (parser->line[parser->i] == '\'')
		arg = single_quote_proccesing(parser, arg);
	if (parser->line[parser->i] == '"')
		arg = double_quote_proccesing(parser, env, arg);
	if (parser->line[parser->i] == '$')
		arg = path_proccesing(parser, env, arg);
	return (arg);
}

static char	*parse_spec_smb_first(t_parser *parser, char *arg)
{
	int		i;
	char	*tmp;

	i = parser->i + 1;
	while (parser->line[i] == ' ')
		i++;
	if (parser->line[i] != '\0' && ft_strchr(";<>|", parser->line[i]))
		arg = error_lexer(parser, arg, "syntax error near unexpected token.");
	else if (ft_strchr(";", parser->line[parser->i]) && parser->q_arg == 0)
		arg = error_lexer(parser, arg, "syntax error near unexpected token.");
	else if (ft_strchr("<>", parser->line[parser->i]) && (
			parser->line[parser->i + 1] == '\0'))
		arg = error_lexer(parser, arg, "syntax error near unexpected token.");
	else if (ft_strchr("|", parser->line[parser->i]) && (
			parser->line[parser->i + 1] == '\0'))
		arg = error_lexer(parser, arg, "multiline commands.");
	else
	{
		tmp = arg;
		arg = ft_strjoin("\t", arg);
		free(tmp);
		arg = add_symbol(arg, parser->line[parser->i]);
		parser->i++;
	}
	return (arg);
}

static char	*get_argument_other(t_parser *parser, char **env, char *arg)
{
	while (parser->line[parser->i] && (parser->line[parser->i]
			!= ' ') && !(ft_strchr(";<>|", parser->line[parser->i])))
	{
		if (ft_strchr("'\"$\\", parser->line[parser->i]))
		{
			while (parser->line[parser->i] && (parser->line[parser->i]
					!= ' ') && ft_strchr("'\"$\\", parser->line[parser->i]))
				arg = parse_spec_smb_second(parser, env, arg);
		}
		if (!(ft_strchr(";'\"<>|$\\", parser->line[parser->i])))
		{
			while (parser->line[parser->i] && (
					parser->line[parser->i] != ' ') && (
					!(ft_strchr(";'\"<>|$\\", parser->line[parser->i]))))
			{
				arg = add_symbol(arg, parser->line[parser->i]);
				parser->i++;
			}
		}
	}
	return (arg);
}

char	*get_argument(t_parser *parser, char **env)
{
	char			*arg;

	while (parser->line[parser->i] == ' ')
		parser->i++;
	if (parser->line[parser->i] == '\0')
		return (NULL);
	arg = ft_strdup("");
	if (!arg)
		error_exit_message("Error malloc.", errno);
	if (ft_strchr(";<>|", parser->line[parser->i]))
	{
		if (parser->line[parser->i] == '>' && (
				parser->line[parser->i + 1] == '>'))
		{
			arg = add_symbol(arg, parser->line[parser->i]);
			parser->i++;
		}
		arg = parse_spec_smb_first(parser, arg);
	}
	else
		arg = get_argument_other(parser, env, arg);
	return (arg);
}
