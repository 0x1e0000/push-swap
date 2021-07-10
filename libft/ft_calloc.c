#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;

	c = malloc(count * size);
	if (!c)
		return (0);
	ft_bzero(c, count * size);
	return (c);
}
