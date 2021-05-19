/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:03:11 by prautha           #+#    #+#             */
/*   Updated: 2021/04/07 19:03:13 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*error_lexer(t_parser *parser, char *arg, char *msg)
{
	free(arg);
	error_message(msg, errno);
	parser->wait_exit = 1;
	return (NULL);
}
