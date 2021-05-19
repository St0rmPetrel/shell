/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:00:14 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 18:22:03 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "programm_utils.h"
#include "libft.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	arr_size(const char **arr)
{
	int	ret;

	ret = 0;
	if (!arr)
		return (0);
	while (arr[ret])
		ret++;
	return (ret);
}

char	**ft_arrcpy(char **dest, const char **src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = (char *)(src[i]);
		i++;
	}
	dest[i] = (char *)(src[i]);
	return (dest);
}

char	**ft_arrdupcpy(char **dest, const char **src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup((char *)(src[i]));
		if (!dest[i])
		{
			free_arr(dest);
			error_exit_message("", errno);
		}
		i++;
	}
	dest[i] = (char *)(src[i]);
	return (dest);
}

char	**ft_arrdup(const char **arr)
{
	size_t	arr_len;
	char	**newarr;

	if (!arr)
		return (0);
	arr_len = arr_size(arr) + 1;
	newarr = ft_calloc(arr_len, sizeof(char *));
	if (!newarr)
		error_exit_message("", errno);
	ft_arrdupcpy(newarr, arr);
	return (newarr);
}
