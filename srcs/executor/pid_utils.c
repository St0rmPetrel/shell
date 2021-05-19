/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:45:02 by serma             #+#    #+#             */
/*   Updated: 2021/04/13 13:21:56 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include "data.h"
#include "programm_utils.h"

static int	pids_len(pid_t *pids)
{
	int	ret;
	int	i;

	ret = 0;
	if (!pids)
		return (ret);
	i = 0;
	while (pids[i])
	{
		ret++;
		i++;
	}
	return (ret);
}

static void	pids_cpy(pid_t *dst, pid_t *src)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
}

void	add_pid(pid_t pid, t_data *data)
{
	int		size_pids;
	pid_t	*new_pids;

	size_pids = pids_len(data->pids);
	new_pids = ft_calloc(size_pids + 2, sizeof(pid_t));
	if (!new_pids)
		error_exit_message("", errno);
	pids_cpy(new_pids, data->pids);
	new_pids[size_pids + 1] = 0;
	new_pids[size_pids] = pid;
	free(data->pids);
	data->pids = new_pids;
}

int	wait_all(t_data *state, int status)
{
	size_t	i;

	i = 0;
	while ((state->pids) && (state->pids)[i])
	{
		waitpid((state->pids)[i], &status, 0);
		i++;
	}
	if ((state->pids))
	{
		free(state->pids);
		state->pids = 0;
		return (WEXITSTATUS(status));
	}
	return (status);
}
