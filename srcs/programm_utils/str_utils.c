/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:03:00 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 18:51:49 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "programm_utils.h"

char	*ft_strjoin_free(char *a, char *b)
{
	char	*ret;

	ret = ft_strjoin(a, b);
	if (!ret)
		error_exit_message("", errno);
	free(a);
	return (ret);
}

char	*quotes_take(char *str)
{
	char	*ret;

	ret = ft_strjoin("\"", str);
	if (!ret)
		error_exit_message("", errno);
	ret = ft_strjoin_free(ret, "\"");
	return (ret);
}

char	*ft_strdup_save(char *src)
{
	char	*ret;

	ret = ft_strdup(src);
	if (!ret)
		error_exit_message("", errno);
	return (ret);
}
