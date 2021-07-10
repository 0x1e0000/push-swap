#include "../push_swap.h"

int	check_double_rotate(t_list **a, t_list **b, int *size, int *index)
{
	if (index[0] < size[0] && index[1] < size[1])
		rr(a, b, "rr");
	else if (index[0] >= size[0] && index[1] >= size[1])
		rrr(a, b, "rrr");
	else
		return (1);
	return (0);
}

void	check_rotate_b(int index, int size, t_list **b)
{
	if (index < size)
		rotate(b, "rb");
	else
		r_rotate(b, "rrb");
}

void	check_rotate_a(int index, int size, t_list **a)
{
	if (index < size)
		rotate(a, "ra");
	else
		r_rotate(a, "rra");
}
