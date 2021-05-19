/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:38:23 by telman            #+#    #+#             */
/*   Updated: 2021/04/09 18:22:43 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "programm_utils.h"

int	ft_arradd(char ***arr, char *new)
{
	size_t	newarr_len;
	char	**newarr;

	if (!new || !arr)
		return (1);
	newarr_len = arr_size((const char **)*arr) + 2;
	newarr = ft_calloc(newarr_len, sizeof(char *));
	if (!newarr)
		error_exit_message("", errno);
	newarr[0] = new;
	ft_arrcpy(newarr + 1, (const char **)*arr);
	free(*arr);
	*arr = newarr;
	return (0);
}

int	ft_arradd_back(char ***arr, char *new)
{
	size_t	newarr_len;
	char	**newarr;

	if (!new || !arr)
		return (1);
	newarr_len = arr_size((const char **)*arr) + 2;
	newarr = ft_calloc(newarr_len, sizeof(char *));
	if (!newarr)
		error_exit_message("", errno);
	ft_arrcpy(newarr, (const char **)*arr);
	newarr[newarr_len - 2] = new;
	free(*arr);
	*arr = newarr;
	return (0);
}

static void	swap_str(char **arr, size_t index)
{
	char	*tmp;

	tmp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = tmp;
}

void	arr_sort(char **arr)
{
	size_t	i;
	size_t	j;

	if (arr_size((const char **)arr) < 2)
		return ;
	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[i + 1])
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
				swap_str(arr, i);
			i++;
		}
		j++;
	}
}
