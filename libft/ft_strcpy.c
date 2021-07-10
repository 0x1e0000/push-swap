#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	len;

	len = ft_strlen(src);
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst - len);
}
