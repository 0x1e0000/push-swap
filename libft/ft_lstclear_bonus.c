/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:06:21 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/30 23:44:30 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*save;

	current = *lst;
	while (current)
	{
		save = current->next;
		ft_lstdelone(current, del);
		current = save;
	}
	*lst = NULL;
}
