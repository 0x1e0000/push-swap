MakeDir = make bonus
compile = gcc -Wall -Werror -Wextra
src =	src/operations/push.c			\
		src/operations/reverse_rotate.c	\
		src/operations/rotate.c			\
		src/operations/swap.c			\
		src/*.c
headers = -Ilibft/libft.h
libs = libft/libft.a

all:
	@$(MakeDir) -C libft/
	@$(compile) push_swap.c $(src) -I $(headers) $(libs) -o push_swap -g

bonus:
	@$(MakeDir) -C libft/
	@$(compile) checker.c $(src) -I $(headers) $(libs) -o checker -g

clean:
	@$(MakeDir) clean -C libft/

fclean: clean
	@$(MakeDir) fclean -C libft/
	@rm -rf push_swap
	@rm -rf checker

re: fclean all
