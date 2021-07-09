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
	int	result;
	int	div;
	int	is_found;

	is_found = 0;
	while (stack)
	{
		if (!is_found && stack->content > nbr) // Will execute once
		{
			div = stack->content - nbr;
			result = stack->content;
			is_found = 1;
		}
		if (is_found && stack->content > nbr)
		{
			if (stack->content - nbr < div)
			{
				div = stack->content - nbr;
				result = stack->content;
			}
		}
		stack = stack->next;
	}
	return (result);
}
