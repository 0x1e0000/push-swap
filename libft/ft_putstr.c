#include "libft.h"

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str != '\0')
			write(1, &*str++, 1);
	}
}
