/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:21:46 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/06 23:02:45 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_list **stack, char *print)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	ss(t_list **stack_a, t_list **stack_b, char *print)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (print)
		ft_putstr("sa\nsb\n");
}
