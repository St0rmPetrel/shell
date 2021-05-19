/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duo_lstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:18:01 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 14:08:36 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_duo_lstclear(t_duo_list **lst, void (*del)(void*))
{
	t_duo_list	*tmp_list1;
	t_duo_list	*tmp_list2;

	if (!lst || !del)
		return ;
	tmp_list1 = (*lst);
	while (tmp_list1)
	{
		tmp_list2 = tmp_list1->next;
		del(tmp_list1->content);
		free(tmp_list1);
		tmp_list1 = tmp_list2;
	}
	(*lst) = NULL;
}
