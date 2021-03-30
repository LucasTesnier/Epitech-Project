##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS 	=	-I include/

TUSRC	=

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy -lm -lcsfml-graphics -lcsfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run:
	gcc -o unit_tests $(CFLAGS) $(TUSRC) tests/test.c -L./lib/ -lmy -lm \
	-lcsfml-graphics -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all:	$(NAME) clean
