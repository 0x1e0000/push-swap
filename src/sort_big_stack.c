/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:09:19 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/09 01:23:17 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_list **a, t_list **b, int argc)
{
	int		min;
	int		max;
	int		middle;
	// printf("[%d, %d, %d]\n", min, middle, max);
	min = get_min(*a);
	max = get_max(*a);
	middle = get_middle(*a, argc);
	while (*a)
	{
		if ((*a)->content != min && (*a)->content != max) // exclude Min & Max
		{
			push(a, b, "pb");
			// if ((*a)->content < middle)
			// 	rotate(a, "rb");
		}
		else
			*a = (*a)->next;
	}
}
