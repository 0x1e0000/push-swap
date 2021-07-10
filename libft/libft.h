#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

long long		ft_atoi(const char *str, int *is_number);
void			ft_bzero(void *s, size_t n);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr(char *str);
t_list			*ft_lstnew(int content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);

#endif
