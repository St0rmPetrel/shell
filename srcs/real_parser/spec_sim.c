/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:46:57 by telman            #+#    #+#             */
/*   Updated: 2021/04/13 13:53:28 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_utils.h"

int	is_pipe(char *str)
{
	return (!ft_strcmp(str, "\t|"));
}

int	is_semicolon(char *str)
{
	return (!ft_strcmp(str, "\t;"));
}

int	is_out_rd(char *str)
{
	return (!ft_strcmp(str, "\t>"));
}

int	is_out_append_rd(char *str)
{
	return (!ft_strcmp(str, "\t>>"));
}

int	is_in_rd(char *str)
{
	return (!ft_strcmp(str, "\t<"));
}
