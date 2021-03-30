##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run:
	$(MAKE) -C tests/
	./tests/unit_tests

all:	$(NAME) clean
