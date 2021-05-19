/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:18:18 by prautha           #+#    #+#             */
/*   Updated: 2021/02/08 19:18:32 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_pointer(t_list **lst)
{
	t_list	*tmp_list1;
	t_list	*tmp_list2;

	if (!lst)
		return ;
	tmp_list1 = (*lst);
	while (tmp_list1)
	{
		tmp_list2 = tmp_list1->next;
		free(tmp_list1);
		tmp_list1 = tmp_list2;
	}
	(*lst) = NULL;
}
