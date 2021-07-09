/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:34:25 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/09 00:17:12 by 0x10000          ###   ########.fr       */
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

int	get_middle(t_list *stack, int lenght)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = stack;
	int middle_index = lenght / 2;
	while (tmp)
	{
		i = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				i++;
			tmp2 = tmp2->next;
		}
		if (i == middle_index)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	get_index(t_list *a, int nbr)
{
	int	index;

	index = 0;
	while (a->content != nbr)
	{
		index++;
		a = a->next;
	}
	return (index);
}

int	get_closest_number(t_list *stack, int nbr)
{
	int		result;
	int		div;
	int		tmp;

	result = stack->content;
	div = nbr - stack->content;
	stack = stack->next;
	while (stack)
	{
		tmp = nbr - stack->content;
		tmp = tmp < 0 ? tmp * -1 : tmp;
		if (tmp < div)
		{
			result = stack->content;
			div = tmp;
		}
		stack = stack->next;
	}
	return (result);
}
