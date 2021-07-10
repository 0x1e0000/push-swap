#include "../../push_swap.h"

void	rotate(t_list **stack, char *print)
{
	t_list	*tmp;
	t_list	*head;

	if (!*stack || !(*stack)->next)
		return ;
	head = (*stack)->next;
	tmp = *stack;
	ft_lstlast(tmp)->next = *stack;
	(*stack)->next = NULL;
	*stack = head;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, char *print)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (print)
		ft_putstr("rr\n");
}
