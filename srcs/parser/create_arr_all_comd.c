/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_all_comd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:18:53 by prautha           #+#    #+#             */
/*   Updated: 2021/04/15 15:24:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "real_parser.h"
#include "programm_utils.h"

t_smpl_cmd	***create_arr_all_comd(t_data *data, const char *line)
{
	char		**all_arg;
	t_parser	*parser;
	t_smpl_cmd	***all_comd;

	parser = ft_calloc(1, sizeof(t_parser));
	parser->line = ft_strdup(line);
	parser->status = ft_itoa(data->status);
	all_arg = create_arr_all_arg(data, parser);
	if (!all_arg)
	{
		free(parser->line);
		free(parser->status);
		free(parser);
		return (NULL);
	}
	all_comd = real_parser(all_arg);
	free(parser->line);
	free(parser->status);
	free(parser);
	ft_free_array(all_arg, ft_strlen_arr(all_arg));
	return (all_comd);
}
