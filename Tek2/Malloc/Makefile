##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	src/prototype.c			\
		src/my_malloc.c			\
		src/my_free.c			\
		src/my_realloc.c		\
		src/my_calloc.c			\
		src/my_realloc_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra -Wshadow -fPIC -I include/

SRC_T	=	tests

TEST_N	=	unit_tests

TFLAGS	=	-lcriterion --coverage -I include/

all: $(NAME)

$(NAME): $(OBJ)
	gcc -fPIC -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno'
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	rm -f $(NAME)
	rm -f src/*.o
	rm -f src/pokemon_fight/*.o

tests_run:
	gcc -o $(TEST_N) $(SRC_T) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

test_main:	$(NAME)
	export LD_LIBRARY_PATH=/home/Lucas/delivery/Tek2
		/Malloc/libmy_malloc.so:$$LD_LIBRARY_PATH
	gcc tests/main_test.c -o mainRun
	LD_PRELOAD=libmy_malloc.so ./mainRun
	unset LD_PRELOAD
	unset LD_LIBRARY_PATH
	rm -f mainRun

re: fclean all

dbg: CFLAGS += -g
dbg: re
