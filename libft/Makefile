NAME		=		libft.a

SRCS		=		ft_atoi.c 				\
					ft_strdup.c 			\
					ft_isdigit.c 			\
					ft_calloc.c 			\
					ft_strlen.c 			\
					ft_strchr.c 			\
					ft_strcpy.c 			\
					ft_strjoin.c 			\
					ft_bzero.c 				\
					ft_putstr.c

BSRCS		=		ft_lstnew_bonus.c 		\
					ft_lstsize_bonus.c 		\
					ft_lstlast_bonus.c

BOBJS		=		$(BSRCS:.c=.o)

OBJS		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(NAME)
	@gcc -Wall -Wextra -Werror -c $(BSRCS)
	@ar -rs $(NAME) $(BOBJS)

clean:
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
