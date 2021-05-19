/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:23:34 by prautha           #+#    #+#             */
/*   Updated: 2020/11/10 10:03:10 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_list1;
	t_list	*tmp_list2;

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
