/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:09:20 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/07 12:02:49 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **a)
{
	while (!is_sorted(*a))
	{
		if ((*a)->content > (*a)->next->content)
			swap(a, "sa");
		if ((*a)->next->content > (*a)->next->next->content)
			r_rotate(a, "rra");
	}
}

void	sort_4(t_list **a, t_list **b)
{
	int min;

	min = get_min(*a);
	if (min == (*a)->content)
		push(a, b, "pb");
	if (min == (*a)->next->content)
	{
		swap(a, "sa");
		push(a, b, "pb");
	}
	if (min == (*a)->next->next->content)
	{
		r_rotate(a, "rra");
		r_rotate(a, "rra");
		push(a, b, "pb");
	}
	if ((*a)->next->next->next && min == \
	(*a)->next->next->next->content)
	{
		r_rotate(a, "rra");
		push(a, b, "pb");
	}
	sort_3(a);
	push(b, a, "pa");
}

void	sort_5(t_list **a, t_list **b)
{
	int min;
	int max;
	int i;

	min = get_min(*a);
	max = get_max(*a);
	i = 0;
	while (a)
	{
		if (min == (*a)->content && i++)
			push(a, b, "pb");
		if (max == (*a)->content && i++)
			push(a, b, "pb");
		if (i == 2)
		{
			sort_3(a);
			push(b, a, "pa");
			rotate(a, "ra");
			push(b, a, "pa");
		}
		*a = (*a)->next;
	}
}
