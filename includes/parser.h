/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:38:31 by telman            #+#    #+#             */
/*   Updated: 2021/03/30 18:04:24 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include "libft.h"
# include "terminal.h"
# include "data.h"
# include "command.h"
# include "ft_signal.h"
# include "programm_utils.h"

# define WORK_PROGRAMM 1

typedef struct s_parser
{
	int			i;
	int			q_arg;
	int			wait_exit;
	char		*line;
	char		*status;
}				t_parser;

t_smpl_cmd		***parser(t_data *data, char **env);
t_smpl_cmd		***create_arr_all_comd(t_data *data, const char *line);
char			**create_arr_all_arg(t_data *data, t_parser *parser);
char			*get_argument(t_parser *parser, char **env);
char			*path_proccesing(t_parser *parser, char **env, char *arg);
char			*shielding_proccesing(t_parser *parser, char *arg);
char			*single_quote_proccesing(t_parser *parser, char *arg);
char			*double_quote_proccesing(t_parser *p, char **e, char *a);
char			*left_redirect(t_parser *parser, char *arg);
char			*right_redirect(t_parser *parser, char *arg);
char			*right_redirect_in_end(t_parser *parser, char *arg);
char			*error_lexer(t_parser *parser, char *arg, char *msg);

#endif
