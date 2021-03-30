##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	106bombyx

CFLAGS	=	-I./include/

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o unit_tests src/push_swap.c tests/test.c -L./lib/ -lmy -I./include/ -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all:	$(NAME) clean
