##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-I./include/

SRC_T	=	tests/test.c\
		src/read.c\
		src/sokoban_setup.c\
		src/verification_map.c\
		src/display_map.c\
		src/loosing_winning.c\
		src/moove.c\
		src/setup_cases.c

TEST_N	=	unit_tests

LIB	=	-L./lib/ -lmy

TFLAGS	=	-lcriterion --coverage -I include/ -lncurses

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/ --exclude src/display_map.c
	gcovr --exclude tests/ --exclude src/display_map.c --branches

all: $(NAME) clean
