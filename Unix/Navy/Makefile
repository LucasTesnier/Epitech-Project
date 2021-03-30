##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	:=	$(wildcard src/*.c)
TEST_SRC := $(shell find tests/ -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I include/ -L./lib/ -lmy
TEST_FLAGS = -lcriterion --coverage


$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(MAKE) -C bonus/ clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C bonus/ clean
	$(MAKE) -C bonus/ fclean
	rm -f $(NAME)

re: fclean all

tests_run: $(NAME)
	$(CC) -o tests/test.out $(TEST_SRC) $(filter-out src/main.c, $(SRC)) $(TEST_FLAGS) $(CFLAGS)
	./tests/test.out
	gcovr --exclude tests/
	gcovr --exclude tests/ --branche

bonus:
	$(MAKE) -C bonus/

debug: CFLAGS += -g
debug: fclean $(NAME)

all:	$(NAME)

.PHONY = clean fclean re tests_run debug all