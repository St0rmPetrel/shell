/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_all_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:24:18 by prautha           #+#    #+#             */
/*   Updated: 2021/04/13 11:43:06 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**create_arr(t_list **head, int quantity_strings)
{
	int		i;
	t_list	*tmp;
	char	**config;

	tmp = *head;
	config = ft_calloc(quantity_strings + 1, sizeof(char *));
	if (!config)
		return (NULL);
	i = 0;
	while (tmp)
	{
		config[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (config);
}

char	**create_arr_all_arg(t_data *data, t_parser *parser)
{
	int		q;
	char	*arg;
	char	**all_arg;
	t_list	*head;

	head = NULL;
	q = ft_strlen(parser->line);
	while (parser->i < q)
	{
		arg = get_argument(parser, data->env);
		if (arg == NULL && parser->wait_exit)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		if (!(ft_lstadd_back(&head, ft_lstnew(arg))))
			error_exit_message("Error malloc.", errno);
		parser->q_arg++;
	}
	all_arg = create_arr(&head, ft_lstsize(head));
	if (!all_arg)
		error_exit_message("Error malloc.", errno);
	ft_lstclear_pointer(&head);
	return (all_arg);
}
