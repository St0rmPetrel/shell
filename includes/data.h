/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:39:44 by serma             #+#    #+#             */
/*   Updated: 2021/04/12 15:57:18 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <sys/types.h>
# include "libft.h"

typedef struct s_data
{
	int			status;
	char		**env;
	pid_t		*pids;
	t_duo_list	*history;
}				t_data;

void	add_pid(pid_t pid, t_data *data);
int		wait_all(t_data *state, int status);

#endif
