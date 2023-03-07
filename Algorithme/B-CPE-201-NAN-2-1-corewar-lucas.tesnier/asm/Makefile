##
## EPITECH PROJECT, 2021
## B-CPE-201-NAN-2-1-corewar-lucas.tesnier
## File description:
## Makefile
##

SRC	:=	src/main.c	\
		src/asm.c	\
		src/error_handling.c	\
		src/read_file.c			\
		src/parse_file.c			\
		src/get_champions.c	\
		src/insert_instruction.c	\
		src/create_instruction.c	\
		src/args_type/check_argument_type.c	\
		src/insert_towrite.c \
		src/utils/array_size.c	\
		src/utils/get_program_size.c \
		src/op.c	\
		src/labels_manager/compute_label_offset.c \
		src/get_node_size.c \
		src/insert_size.c \
		src/write_into_cor_file.c \
		src/get_new_file_name.c \

CC := gcc

OBJ	:=	$(SRC:.c=.o)

NAME	:=	asm

CFLAGS	:=	-I./include/ -I../my -L../my -lmy -W -Wall -Wshadow

SRC_T	:= tests/test_asm.c

TEST_N	:=	unit_tests

TFLAGS	:=	-I./include/ -I../my -L../my -lmy -lcriterion --coverage

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: all

tests_run:
	$(MAKE) -C ../my
	gcc -o $(TEST_N) $(filter-out src/main.c, $(SRC)) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all: $(NAME)

.PHONY: clean fclean re tests_run all debug
