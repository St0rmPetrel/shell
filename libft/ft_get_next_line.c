/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:55:09 by prautha           #+#    #+#             */
/*   Updated: 2021/02/08 19:19:38 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_string(size_t i, char *buffer, char **line, char **residue)
{
	char	*arr_tmp[2];

	if (i == ft_strlen(buffer))
		ft_write_string_one(buffer, line);
	else
	{
		arr_tmp[0] = ft_substr(buffer, 0, i++);
		if (!(arr_tmp[0]))
			return (-1);
		arr_tmp[1] = *line;
		*line = ft_strjoin(arr_tmp[1], arr_tmp[0]);
		if (!(*line))
			return (-1);
		if (*residue)
			free(*residue);
		*residue = ft_substr(buffer, i, (ft_strlen(buffer) - i));
		if (!(*residue))
			return (-1);
		free(arr_tmp[0]);
		free(arr_tmp[1]);
		return (0);
	}
	return (1);
}

static int	read_string(int fd, char *buffer, char **line, char **residue)
{
	size_t	i;
	int		q;
	int		f;

	f = 1;
	q = read(fd, buffer, BUFFER_SIZE);
	while (f && (q != 0))
	{
		if (q == -1)
			return (-1);
		buffer[q] = '\0';
		i = -1;
		while (buffer[++i])
			if (buffer[i] == '\n')
				break ;
		f = write_string(i, buffer, line, residue);
	}
	return (q);
}

static void	check_end_str(char *arr, int *i)
{
	if (arr[(*i)] == '\0')
		*i = 0;
	else
		(*i)++;
}

static int	check_residue(char **residue, char **line)
{
	int			j;
	static int	i;
	char		*arr;

	if (!(*residue))
		*line = ft_strdup("");
	else
	{
		arr = *residue;
		j = i;
		while (arr[i] != '\n' && arr[i])
			i++;
		if ((ft_strlen(arr) == 1) && arr[0] == '\n' && arr[1] == '\0')
			*line = ft_strdup("");
		else
			*line = ft_substr(arr, j, (i - j));
		check_end_str(arr, &i);
	}
	if (!(*line))
		return (-1);
	return (i);
}

int	ft_get_next_line(int fd, char **line)
{
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	static char	*residue;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || (
			read(fd, NULL, 0)) < 0 || !line)
		return (-1);
	*line = NULL;
	i = check_residue(&residue, line);
	if (i == 0)
		i += read_string(fd, buffer, line, &residue);
	if (i <= 0)
	{
		if (residue)
		{
			free(residue);
			residue = NULL;
		}
		if (i == 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}
