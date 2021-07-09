/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/07 00:14:19 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	r_rotate(t_list **stack, char *print)
{
	t_list *tmp;
	t_list *head;

	if (!*stack || !(*stack)->next)
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
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, char *print)
{
	r_rotate(stack_a, NULL);
	r_rotate(stack_b, NULL);
	if (print)
		ft_putstr("rra\nrrb\n");
}
