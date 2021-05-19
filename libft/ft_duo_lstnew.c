/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:20:48 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:07:14 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_duo_list	*ft_duo_lstnew(void *content)
{
	t_duo_list	*list;

	list = (t_duo_list *)malloc(sizeof(t_duo_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
