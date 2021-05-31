/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/31 01:06:43 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	r_rotate(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	if (!*stack)
		return ;
	tmp = *stack;
	head = ft_lstlast(tmp);
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	head->next = *stack;
	*stack = head;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}
