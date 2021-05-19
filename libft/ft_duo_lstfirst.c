/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:59:58 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:07:54 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_duo_list	*ft_duo_lstfirst(t_duo_list *lst)
{
	t_duo_list	*list;

	list = lst;
	if (list)
	{
		while (list->prev)
			list = list->prev;
		return (list);
	}
	return (NULL);
}
