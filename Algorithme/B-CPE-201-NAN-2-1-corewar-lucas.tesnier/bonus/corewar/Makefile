##
## EPITECH PROJECT, 2021
## B-CPE-201-NAN-2-1-corewar-lucas.tesnier
## File description:
## Makefile
##

INSTRCUT :=	src/instructions/live.c				\
			src/instructions/ld.c				\
			src/instructions/convert_values.c	\
			src/instructions/parameters.c		\
			src/instructions/scheduling.c		\
			src/instructions/change_pc.c		\
			src/instructions/mem_write.c		\
			src/instructions/st.c				\
			src/instructions/add.c				\
			src/instructions/sub.c				\
			src/instructions/and.c				\
			src/instructions/or.c				\
			src/instructions/xor.c				\
			src/instructions/zjmp.c				\
			src/instructions/ldi.c				\
			src/instructions/sti.c				\
			src/instructions/fork.c				\
			src/instructions/lld.c				\
			src/instructions/lldi.c				\
			src/instructions/lfork.c			\
			src/instructions/aff.c				\

SRC	:=  src/main.c								\
		src/op.c								\
		src/champion_init.c						\
		src/flag_handling.c						\
		src/struct_init.c						\
		src/champ_mem_init.c					\
		src/champ_flags_handling.c				\
		src/memory_init.c						\
		src/unsigned_operations.c				\
		src/hexdump_display.c					\
		src/corewar_loop.c						\
		src/graph.c								\
		$(INSTRCUT)								\

CC := gcc

OBJ	:=	$(SRC:.c=.o)

NAME	:=	corewar

CFLAGS	:=	-I./include/ -I../../my -L../../my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

SRC_T	:=

TEST_N	:=	unit_tests

TFLAGS	:=	-lcriterion --coverage

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) -f $(OBJ)
	$(MAKE) -C ../../my clean

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

tests_run:
	$(MAKE) -C ../my
	$(CC) -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all: $(NAME)

.PHONY: clean fclean re tests_run all debug
