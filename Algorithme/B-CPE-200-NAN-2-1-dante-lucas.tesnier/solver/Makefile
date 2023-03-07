##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/graph/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-I./include/ -lm -O3

SRC_T	=

TEST_N	=	unit_tests

TFLAGS	=	-lcriterion --coverage -I ./include/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: all

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all: $(NAME)

.PHONY: clean fclean re tests_run all debug