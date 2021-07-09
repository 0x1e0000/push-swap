#include "../push_swap.h"

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

int	get_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
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

int	get_max_index(t_list *a)
{
	int	index;
	int	max;

	index = 0;
	max = get_max(a);
	while (a->content != max)
	{
		index++;
		a = a->next;
	}
	return (index);
}

void	exclude_min_max(t_list **a, t_list **b, int lenght, int switcher)
{
	int	index;
	int	i;

	i = 0;
	if (switcher)
		index = get_min_index(*a);
	else
		index = get_max_index(*a);
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
