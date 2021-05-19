/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:26:26 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:10:06 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_duo_lstadd_back(t_duo_list **lst, t_duo_list *new)
{
	t_duo_list	*list;

	if (!lst || !new)
		return (0);
	if (!(*lst))
		*lst = new;
	else
	{
		list = ft_duo_lstlast(*lst);
		list->next = new;
		new->prev = list;
	}
	return (1);
}
