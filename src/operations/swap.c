#include "../../push_swap.h"

void	swap(t_list **stack, char *print)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	ss(t_list **stack_a, t_list **stack_b, char *print)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (print)
		ft_putstr("sa\nsb\n");
}
