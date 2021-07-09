#include "../push_swap.h"

void	sort_3(t_list **a)
{
	int	_1;
	int	_2;
	int	_3;

	_1 = (*a)->content;
	_2 = (*a)->next->content;
	_3 = (*a)->next->next->content;
	if (_1 < _2 && _1 < _3 && _2 > _3)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (_1 > _2 && _1 < _3 && _2 < _3)
		swap(a, "sa");
	else if (_1 < _2 && _1 > _3 && _2 > _3)
		r_rotate(a, "rra");
	else if (_1 > _2 && _1 > _3 && _2 < _3)
		rotate(a, "ra");
	else if (_1 > _2 && _1 > _3 && _2 > _3)
	{
		swap(a, "sa");
		r_rotate(a, "rra");
	}
}

void	sort_4(t_list **a, t_list **b, int argc)
{
	exclude_min_max(a, b, argc, 1);
	sort_3(a);
	push(b, a, "pa");
}

void	sort_5(t_list **a, t_list **b, int argc)
{
	exclude_min_max(a, b, argc, 1);
	sort_4(a, b, argc - 1);
	push(b, a, "pa");
}
