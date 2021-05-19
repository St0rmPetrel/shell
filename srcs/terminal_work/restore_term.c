/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:30:01 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 14:30:31 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	restore_term(struct termios *save_term, char *err_msg)
{
	tcsetattr(STDIN_FILENO, TCSANOW, save_term);
	tgetent(STDIN_FILENO, getenv("TERM"));
	free(save_term);
	if (err_msg)
	{
		write(STDOUT_FILENO, "\n", 1);
		error_exit_message(err_msg, errno);
	}
}
