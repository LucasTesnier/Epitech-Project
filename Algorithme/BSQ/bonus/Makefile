##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy -I include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o unit_tests src/bsq.c src/read.c src/buffer.c src/transformation_bsq.c tests/test.c -L./lib/ -lmy -I include/ -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branche
	rm *.gcda
	rm *.gcno

all:	$(NAME) clean
