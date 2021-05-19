/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quote_proccesing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:21 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 11:46:41 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*double_quote_proccesing(t_parser *parser, char **env, char *arg)
{
	parser->i++;
	while (parser->line[parser->i] && parser->line[parser->i] != '"')
	{
		if (parser->line[parser->i] == '\\')
			arg = shielding_proccesing(parser, arg);
		else if (parser->line[parser->i] == '$')
			arg = path_proccesing(parser, env, arg);
		else
		{
			arg = add_symbol(arg, parser->line[parser->i]);
			parser->i++;
		}
	}
	if (parser->line[parser->i] != '"')
		arg = error_lexer(parser, arg, "multiline commands.");
	else
		parser->i++;
	return (arg);
}
