/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shielding_proccesing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:29:51 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 13:10:35 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*shielding_proccesing(t_parser *parser, char *arg)
{
	parser->i++;
	if (parser->line[parser->i] == '\0')
		arg = error_lexer(parser, arg, "multiline commands.");
	else
	{
		arg = add_symbol(arg, parser->line[parser->i]);
		parser->i++;
	}
	return (arg);
}
