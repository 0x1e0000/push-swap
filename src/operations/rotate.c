/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/30 23:50:01 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	if (!*stack)
		return ;
	head = (*stack)->next; // seconde node is the head
	tmp = *stack;
	ft_lstlast(tmp)->next = *stack;
	(*stack)->next = NULL;
	*stack = head;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
