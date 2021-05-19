/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_false_smpl_cmnd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:26:50 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 07:30:53 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "command.h"
#include "programm_utils.h"

t_smpl_cmd	*fill_false_smpl_cmnd(void)
{
	t_smpl_cmd	*ret;

	ret = ft_calloc(1, sizeof(t_smpl_cmd));
	if (!ret)
		error_exit_message("", errno);
	ret->argv = ft_calloc(2, sizeof(char *));
	if (!(ret->argv))
		error_exit_message("", errno);
	(ret->argv)[0] = ft_strdup("false");
	if (!(ret->argv)[0])
		error_exit_message("", errno);
	return (ret);
}
