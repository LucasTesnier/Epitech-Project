##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC1	=	src/giantman.c\
		src/uncompression.c\
		src/decryption_tree.c\
		src/global_function.c\
		src/bit_gestion.c

CFLAGS	=	-I include/

TEST_N	=	unit_tests

SRC_T	=	src/uncompression.c\
		src/global_function.c\
		src/decryption_tree.c\
		src/bit_gestion.c\
		tests/test.c

OBJ1	=	$(SRC1:.c=.o)

NAME1	=	giantman

CFLAGS	=	-I include/

all: $(NAME1)

$(NAME1): $(OBJ1)
	gcc -o $(NAME1) $(OBJ1) -L../lib/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME1)

tests_run:
	gcc -o $(TEST_N) $(SRC_T) -L../lib/ -lmy -lcriterion --coverage -I include/

re: fclean all

