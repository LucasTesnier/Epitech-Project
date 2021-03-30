##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./include/

SRC_T	=	tests/test.c\
		src/bultins.c\
		src/env_parsing.c\
		src/path_gestion.c\
		src/setup.c\
		src/shell.c

TEST_N	=	unit_tests

LIB	=	-L./lib/ -lmy

TFLAGS	=	-lcriterion --coverage -I include/

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all: $(NAME) clean
