#include "../push_swap.h"

static char	*check_stock(char **line, char *stock)
{
	char	*ptr;

	ptr = NULL;
	if (stock)
	{
		ptr = ft_strchr(stock, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strdup(stock);
			ft_strcpy(stock, ++ptr);
		}
		else
		{
			*line = ft_strdup(stock);
			stock = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (ptr);
}

static int	end_of_file(char *buff, char **stock)
{
	free(buff);
	free(*stock);
	*stock = NULL;
	return (0);
}

static int	read_line(char **stock, int fd, char **line, char *buff)
{
	char	*ptr;
	char	*helper;
	int		ret;

	ptr = check_stock(line, *stock);
	while (!ptr)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (!ret)
			return (end_of_file(buff, &*stock));
		*(buff + ret) = '\0';
		ptr = ft_strchr(buff, '\n');
		if (ptr)
		{
			*ptr = '\0';
			free(*stock);
			*stock = ft_strdup(++ptr);
		}
		helper = *line;
		*line = ft_strjoin(*line, buff);
		free(helper);
	}
	free(buff);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*stock[1024];

	if (BUFFER_SIZE >= MAX_INT)
		return (-1);
	if (fd < 0 || !line || (read(fd, NULL, 0) != 0))
		return (-1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	return (read_line(&stock[fd], fd, line, buff));
}
