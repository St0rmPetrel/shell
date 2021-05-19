/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:49 by prautha           #+#    #+#             */
/*   Updated: 2021/04/15 19:07:31 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "programm_utils.h"

void	error_message(char *err_msg, int my_errno)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err_msg, 2);
	if ((my_errno) && (*err_msg != '\0'))
		ft_putstr_fd(": ", 2);
	if (my_errno)
		ft_putstr_fd(strerror(my_errno), 2);
	ft_putstr_fd("\n", 2);
}

void	error_exit_message(char *err_msg, int my_errno)
{
	error_message(err_msg, my_errno);
	exit(my_errno);
}

void	builtin_error_message(char *prog, char *arg, char *error_mes)
{
	char	*done_str;
	char	*quoter_arg;

	done_str = ft_strjoin(prog, ": ");
	if (!done_str)
		error_exit_message("", errno);
	quoter_arg = quotes_take(arg);
	done_str = ft_strjoin_free(done_str, quoter_arg);
	free(quoter_arg);
	done_str = ft_strjoin_free(done_str, ": ");
	done_str = ft_strjoin_free(done_str, error_mes);
	error_message(done_str, 0);
	free(done_str);
}
