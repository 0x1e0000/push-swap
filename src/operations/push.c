#include "../../push_swap.h"

void	push(t_list **from, t_list **to, char *print)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}
