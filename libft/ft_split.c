/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:47:39 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 12:08:57 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_words(char const *s, char c)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static int	ft_len_w(char const *s, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

static void	*ft_free_arr(char **arr_gen, int q)
{
	int	i;

	i = 0;
	while (i < q)
	{
		free(arr_gen[i]);
		i++;
	}
	free(arr_gen);
	return (NULL);
}

static char	**ft_strdup_str(char const *s, int q, char c, char **arr_gen)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	while (i < q)
	{
		while (*s == c)
			s++;
		l = ft_len_w(s, c);
		arr_gen[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!(arr_gen[i]))
			return (ft_free_arr(arr_gen, i));
		j = 0;
		while (j < l)
		{
			arr_gen[i][j] = *s;
			j++;
			s++;
		}
		arr_gen[i][j] = '\0';
		i++;
	}
	arr_gen[i] = NULL;
	return (arr_gen);
}

char	**ft_split(char	const *s, char c)
{
	char	**arr_gen;
	int		q;

	if (!s)
		return (NULL);
	q = ft_quantity_words(s, c);
	arr_gen = (char **)malloc(sizeof(char *) * (q + 1));
	if (!arr_gen)
		return (NULL);
	arr_gen = ft_strdup_str(s, q, c, arr_gen);
	return (arr_gen);
}
