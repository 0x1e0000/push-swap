#include "push_swap.h"

static int	quit(t_list **list, int ret)
{
	free_stack(list);
	return (ret);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	if (argc > 1 && argv && !fill_stack(argv, &a))
		return (0);
	while (get_next_line(0, &instruction))
	{
		execute_instruction(instruction, &a, &b);
		free(instruction);
	}
	free(instruction);
	if (!is_sorted(a))
	{
		write(2, "KO\n", 3);
		return (quit(&a, 1));
	}
	write(2, "OK\n", 3);
	return (quit(&a, 0));
}
