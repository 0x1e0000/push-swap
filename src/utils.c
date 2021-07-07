/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:34:25 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/07 13:42:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack->next && stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	error_(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_index(t_list *a)
{
	int	index;
	int	min;

	index = 0;
	min = get_min(a);
	while (a->content != min)
	{
		index++;
		a = a->next;
	}
	return (index);
}

void	exclude_min(t_list **a, t_list **b, int lenght)
{
	int	index;
	int	i;

	i = 0;
	index = get_min_index(*a);
	if (index > lenght / 2)
	{
		index = lenght - index;
		i = 2;
	}
	if (i != 2)
	{
		while (index-- > 0)
			rotate(a, "ra");
		push(a, b, "pb");
	}
	else
	{
		while (index-- > 0)
			r_rotate(a, "rra");
		push(a, b, "pb");
	}
}
