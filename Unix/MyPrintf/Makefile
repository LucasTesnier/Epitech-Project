##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard sources/*.c)\
		$(wildcard lib/my/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean tests_run

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
	rm ../$(NAME)

tests_run:
	gcc -o unit_tests tests/test_unitaire.c $(SRC) -lcriterion --coverage
	./unit_tests
	gcovr --exclude test --exclude lib
	rm *.gcda
	rm *.gcno

re: fclean all
