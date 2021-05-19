/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:31:54 by telman            #+#    #+#             */
/*   Updated: 2021/04/16 14:02:10 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_signal.h"
#include "builtin.h"

void	ctrl_d(t_data *state)
{
	ft_exit(0, state);
}

void	handle_sigint(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		g_is_sigint = 1;
	}
}
