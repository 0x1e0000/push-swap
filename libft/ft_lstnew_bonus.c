#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(*list) + 1);
	if (!list)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
