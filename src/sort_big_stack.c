/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:09:19 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/09 20:02:33 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_stack(t_list **a, t_list **b, int argc)
{
	int		min;
	int		max;
	int		middle;

	min = get_min(*a);
	max = get_max(*a);
	middle = get_middle(*a, argc);
	argc++;
	while (argc--)
	{
		if ((*a)->content == min || (*a)->content == max)
			rotate(a, NULL);
		else
		{
			push(a, b, NULL);
			if ((*b)->content < middle)
				rotate(b, NULL);
		}
	}
	if ((*a)->next && (*a)->content < (*a)->next->content)
		swap(a, NULL);
}

int	get_moves(t_list *stack, int nbr)
{
	int		index;
	int		size;
	t_list	*head;

	head = stack;
	size = ft_lstsize(stack);
	while (stack)
	{
		if (stack->content == nbr)
		{
			index = get_index(head, nbr);
			if (index <= size / 2)
				return (index);
			return (size - index);
		}
		stack = stack->next;
	}
	return (0);
}

int	*get_less_moves(t_list *a, t_list *b)
{
	static int	result[3];
	t_list *tmp;
	int sum;

	tmp = b;
	result[0] = tmp->content; // first value
	result[1] = get_closest_number(a, result[0]); // Clossest b Number in stack A
	result[2] = get_moves(b, result[0]) + get_moves(a, result[1]) + 1; // Total Moves to put b next to clossest number in A
	tmp = tmp->next;
	while (tmp)
	{
		result[0] = tmp->content;
		result[1] = get_closest_number(a, result[0]);
		sum = get_moves(b, result[0]) + get_moves(a, result[1]) + 1;
		if (sum < result[2])
			result[2] = sum;
		tmp = tmp->next;
	}
	return (result);
}

void	move(int *result, t_list **a, t_list **b)
{
	// if (result[2] == 1)
	// 	push(b, a, NULL);
	while (result[1] != (*b)->content)
		rotate(b, NULL);
	while (result[0] != (*a)->content)
		rotate(a, NULL);
	// push(b, a, NULL);
}

void	big_sort(t_list **a, t_list **b, int argc)
{
	int	*result;
	split_stack(a, b, argc);
	t_list *tmp;

	result = get_less_moves(*a, *b);
	printf("Number [%d] Closest to [%d] Needs [%d] Moves\n", result[0], result[1], result[2]);
	tmp = *b;
	// while (tmp)
	// {
	// 	move(result, a, b);
	// 	tmp = tmp->next;
	// }
}

// printf("[%d] needs %d move to be in top\n", tmp->content, get_moves(tmp->content, *b));
