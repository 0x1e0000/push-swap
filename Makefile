MakeDir = make
compile = gcc -Wall -Werror -Wextra
NAME = push_swap
src = main.c src/*.c src/operations/*.c
headers = -Ilibft/libft.h
libs = libft/libft.a

all: $(NAME)

$(NAME):
	@$(MakeDir) -C libft/
	@$(compile) $(src) -I $(headers) $(libs) -o $(NAME) -g

bonus: $(NAME)

clean:
	@$(MakeDir) clean -C libft/

fclean: clean
	@$(MakeDir) fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
