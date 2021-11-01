#include "../push_swap.h"

static int split_stack(t_list **a, t_list **b, int argc)
{
	int min;
	int max;
	int middle;

	min = get_min(*a);
	max = get_max(*a);
	middle = get_middle(*a, argc);
	argc++;
	while (argc--)
	{
		// Push values from Stack A to B except for min, and max values.
		if ((*a)->content == min || (*a)->content == max)
			rotate(a, "ra");
		else
		{
			push(a, b, "pb");
			// if the current value less than the middle value, we will rotate Stack B to keep the Stack Splited with middle value
			if ((*b)->content < middle)
				rotate(b, "rb");
		}
	}
	// Stack A. will be swapper if the min value is above (so we will have Stack A with 2 Values => [max, min])
	if ((*a)->next && (*a)->content < (*a)->next->content)
		swap(a, "sa");
	return (min);
}

static int get_moves(t_list *stack, int nbr)
{
	int index;
	int size;
	t_list *head;

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

static int *get_less_moves(t_list *a, t_list *b)
{
	static int result[3];
	t_list *tmp;
	int sum;
	int tmp2[2];

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

static void rotate_stacks(int *result, t_list **a, t_list **b)
{
	int size[2];
	int index[2];

	if (result[2] != 1)
	{
		size[0] = ft_lstsize(*b) / 2;
		index[0] = get_index(*b, result[0]);
		size[1] = ft_lstsize(*a) / 2;
		index[1] = get_index(*a, result[1]);
		while (result[0] != (*b)->content && result[1] != (*a)->content)
			if (check_double_rotate(a, b, size, index))
				break;
		while (result[0] != (*b)->content)
			check_rotate_b(index[0], size[0], b);
		while (result[1] != (*a)->content)
			check_rotate_a(index[1], size[1], a);
	}
}

void big_sort(t_list **a, t_list **b, int argc)
{
	int min;

	// Push all A elements to B except min, max number.
	// Stack B will have. first half with numbers grater than the middle.
	// and the other half for the smallest numbers (no need to be sorted)
	min = split_stack(a, b, argc);
	while (*b)
	{
		rotate_stacks(get_less_moves(*a, *b), a, b);
		push(b, a, "pa");
	}
	while (*a)
	{
		if (min == (*a)->content)
			break;
		r_rotate(a, "rra");
	}
}
