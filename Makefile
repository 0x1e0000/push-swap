NAME 		= 	push_swap
NAME_BONUS	= 	checker
MakeDir		= 	make bonus
compile		= 	gcc -Wall -Werror -Wextra
src 		=	src/operations/push.c			\
				src/operations/reverse_rotate.c	\
				src/operations/rotate.c			\
				src/operations/swap.c			\
				src/exclude_min_max.c			\
				src/execute_instruction.c		\
				src/fill_stack.c				\
				src/get_next_line.c				\
				src/sort_big_stack.c			\
				src/sort_small_stack.c			\
				src/utils.c						\
				src/utils2.c
headers		=	-Ilibft/libft.h
libs 		=	libft/libft.a

all: $(NAME)

$(NAME): $(src)
	@$(MakeDir) -C libft/
	@$(compile) push_swap.c $(src) -I $(headers) $(libs) -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): checker.c
	@$(MakeDir) -C libft/
	@$(compile) checker.c $(src) -I $(headers) $(libs) -o checker

clean:
	@$(MakeDir) clean -C libft/

fclean: clean
	@$(MakeDir) fclean -C libft/
	@rm -rf push_swap
	@rm -rf checker

re: fclean all
