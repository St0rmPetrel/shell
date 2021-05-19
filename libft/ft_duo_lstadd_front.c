/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:50:27 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:09:47 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_duo_lstadd_front(t_duo_list **lst, t_duo_list *new)
{
	t_duo_list	*list;

	if (lst && new)
	{
		list = ft_duo_lstfirst(*lst);
		new->next = list;
		if (list)
			list->prev = new;
		*lst = new;
		return (1);
	}
	else
		return (0);
}
