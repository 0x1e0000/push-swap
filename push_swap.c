#include "push_swap.h"

static int	quit(t_list **list)
{
	free_stack(list);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1 && argv && !fill_stack(argv, &a))
		return (0);
	if (is_sorted(a))
		return (quit(&a));
	if (--argc == 2)
		swap(&a, "sa");
	else if (argc == 3)
		sort_3(&a);
	else if (argc == 4)
		sort_4(&a, &b, argc);
	else if (argc == 5)
		sort_5(&a, &b, argc);
	else if (argc <= 500)
		big_sort(&a, &b, --argc);
	return (quit(&a));
}

