/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:51:52 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/30 23:45:16 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	ptr = lst;
	new = ft_lstnew(f(ptr->content));
	ptr = ptr->next;
	while (ptr)
	{
		if (!(elem = ft_lstnew(f(ptr->content))))
		{
			ft_lstclear(&new, del);
			new = NULL;
			break ;
		}
		ft_lstadd_back(&new, elem);
		ptr = ptr->next;
	}
	return (new);
}
