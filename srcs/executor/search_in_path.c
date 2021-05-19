/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:32:39 by telman            #+#    #+#             */
/*   Updated: 2021/04/12 13:25:53 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"
#include "search_in_path.h"
#include "programm_utils.h"

static char	**parse_path(char **envp)
{
	char	*path;

	path = give_env_var("PATH", envp);
	return (ft_split(path, ':'));
}

static char	*find_cmd_path(char *cmd, char **parse_path)
{
	char		*ret;
	int			i;
	struct stat	stats;

	ret = 0;
	i = 0;
	while (parse_path[i])
	{
		ret = ft_strjoin(parse_path[i], cmd);
		if (ret && (stat(ret, &stats) == 0) && (stats.st_mode & X_OK))
			return (ret);
		free(ret);
		i++;
	}
	i = 0;
	while (parse_path[i])
	{
		ret = ft_strjoin(parse_path[i], cmd);
		if (ret && (stat(ret, &stats) == 0))
			return (ret);
		free(ret);
		i++;
	}
	return (0);
}

char	*search_in_path(char *cmd, char **envp)
{
	char		**path;
	char		*new_cmd;
	char		*ret;

	path = parse_path(envp);
	if (!path)
		return (NULL);
	new_cmd = ft_strjoin("/", cmd);
	if (!new_cmd)
		return (NULL);
	ret = find_cmd_path(new_cmd, path);
	free_arr(path);
	free(new_cmd);
	return (ret);
}
