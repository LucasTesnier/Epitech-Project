##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS	=	-I./include/ -O3

SRC_T	=	tests/test.c\
			src/display_game.c\
			src/get_user.c\
			src/ia.c\
			src/loop.c\
			src/setup_match.c\
			src/stick_operations.c\
			src/verification_match.c

TEST_N	=	unit_tests

TFLAGS	=	-lcriterion --coverage -I ./include/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

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
