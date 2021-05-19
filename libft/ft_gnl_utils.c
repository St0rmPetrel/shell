/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:44:23 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:48:29 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write_string_one(char *buffer, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buffer);
	free(tmp);
}
