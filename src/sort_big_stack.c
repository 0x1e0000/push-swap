#include "../push_swap.h"

int	split_stack(t_list **a, t_list **b, int argc)
{
	int	min;
	int	max;
	int	middle;

	min = get_min(*a);
	max = get_max(*a);
	middle = get_middle(*a, argc);
	argc++;
	while (argc--)
	{
		if ((*a)->content == min || (*a)->content == max)
			rotate(a, "ra");
		else
		{
			push(a, b, "pb");
			if ((*b)->content < middle)
				rotate(b, "rb");
		}
	}
	if ((*a)->next && (*a)->content < (*a)->next->content)
		swap(a, "sa");
	return (min);
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
	t_list		*tmp;
	int			sum;
	int			tmp2[2];

	tmp = b;
	result[0] = tmp->content;
	result[1] = get_closest_number(a, result[0]);
	result[2] = get_moves(b, result[0]) + get_moves(a, result[1]) + 1;
	tmp = tmp->next;
	while (tmp)
	{
		tmp2[0] = tmp->content;
		tmp2[1] = get_closest_number(a, tmp2[0]);
		sum = get_moves(b, tmp2[0]) + get_moves(a, tmp2[1]) + 1;
		if (sum < result[2])
		{
			result[0] = tmp2[0];
			result[1] = tmp2[1];
			result[2] = sum;
		}
		tmp = tmp->next;
	}
	return (result);
}

void	move(int *result, t_list **a, t_list **b)
{
	int	size;
	int	index;

	if (result[2] != 1)
	{
		size = ft_lstsize(*b) / 2;
		index = get_index(*b, result[0]);
		while (result[0] != (*b)->content)
		{
			if (index < size)
				rotate(b, "rb");
			else
				r_rotate(b, "rrb");
		}
		size = ft_lstsize(*a) / 2;
		index = get_index(*a, result[1]);
		while (result[1] != (*a)->content)
		{
			if (index < size)
				rotate(a, "ra");
			else
				r_rotate(a, "rra");
		}
	}
	push(b, a, "pa");
}

void	big_sort(t_list **a, t_list **b, int argc)
{
	int	min;

	min = split_stack(a, b, argc);
	while (*b)
		move(get_less_moves(*a, *b), a, b);
	while (*a)
	{
		if (min == (*a)->content)
			break ;
		r_rotate(a, "rra");
	}
}
