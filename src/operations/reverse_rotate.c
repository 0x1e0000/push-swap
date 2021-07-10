#include "../../push_swap.h"

void	r_rotate(t_list **stack, char *print)
{
	t_list	*tmp;
	t_list	*head;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	head = ft_lstlast(tmp);
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	head->next = *stack;
	*stack = head;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, char *print)
{
	r_rotate(stack_a, NULL);
	r_rotate(stack_b, NULL);
	if (print)
		ft_putstr("rrr\n");
}
