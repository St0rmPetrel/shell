/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:33:44 by prautha           #+#    #+#             */
/*   Updated: 2021/04/05 18:33:46 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <term.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft.h"
# include "data.h"
# include "parser.h"
# include "programm_utils.h"

# define ENTER "\n"
# define TAB "\t"
# define CTRL_D "\4"
# define UP "\e[A"
# define DOWN "\e[B"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define BACKSPACE "\177"

typedef struct s_history
{
	char	*act_str;
	char	*tmp_str;
	char	*tmp_h_str;
	short	flag;
	short	ctrl_c;
	short	ctrl_d;
}				t_history;

char	*term_work(t_data *data, short *signal, struct termios *save_term);
void	backspace_response(t_data *data, t_history *history,
			struct termios *save_term);
int		ctrl_d_response(t_history *history);
void	down_response(t_data *data, t_history *history);
int		reaction_on_input(t_data *d, char *b, t_history *h, struct termios *s);
int		receive_str(t_data *d, t_history *h, struct termios *s);
void	up_response(t_data *data, t_history *history);
void	restore_term(struct termios *save_term, char *err_msg);
void	define_str(t_history *history, char	*buff, struct termios *s_t);
int		cmp_history(t_data *data, char *str);
int		is_comd(char *buff);

#endif