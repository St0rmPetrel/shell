/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote_proccesing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:30:50 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 13:10:17 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*single_quote_proccesing(t_parser *parser, char *arg)
{
	parser->i++;
	while (parser->line[parser->i] && parser->line[parser->i] != '\'')
	{
		arg = add_symbol(arg, parser->line[parser->i]);
		parser->i++;
	}
	if (parser->line[parser->i] != '\'')
		arg = error_lexer(parser, arg, "multiline commands.");
	else
		parser->i++;
	return (arg);
}
