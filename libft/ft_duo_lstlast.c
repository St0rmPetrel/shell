/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:43:02 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:07:30 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_duo_list	*ft_duo_lstlast(t_duo_list *lst)
{
	t_duo_list	*list;

	list = lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		return (list);
	}
	return (0);
}
