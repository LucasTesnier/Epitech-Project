##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	src/antman.c\
		src/encryption.c\
		src/global_functions.c\
		src/table.c\
		src/tree.c

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

CFLAGS	=	-I include/

TEST_N	=	unit_tests

SRC_T	=	src/encryption.c\
		src/global_functions.c\
		src/table.c\
		src/tree.c\
		tests/test.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L../lib/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	gcc -o $(TEST_N) $(SRC_T) -L../lib/ -lmy -lcriterion --coverage -I include/

re: fclean all
