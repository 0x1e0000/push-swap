/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/06 23:02:26 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list **stack, char *print)
{
	t_list *tmp;
	t_list *head;

	if (!*stack || !(*stack)->next)
		return ;
	head = (*stack)->next; // seconde node is the head
	tmp = *stack;
	ft_lstlast(tmp)->next = *stack;
	(*stack)->next = NULL;
	*stack = head;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, char *print)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (print)
		ft_putstr("ra\nrb\n");
}
