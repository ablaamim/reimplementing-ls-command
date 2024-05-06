# compile the program

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c

NAME = ft_ls

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	@rm -f $(NAME)

fclean: clean

re: clean all

.PHONY: all clean re fclean