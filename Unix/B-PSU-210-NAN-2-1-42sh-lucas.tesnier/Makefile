##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

FEATURES	=	src/features/globbings/star.c			\
				src/features/globbings/globbings.c		\
				src/features/globbings/utils.c			\
				src/features/inhibitor/inhibitor.c		\
				src/features/inhibitor/bckslash_utils.c	\

BULTINS	=	src/bultins/cd_bultin.c			\
			src/bultins/echo_bultin.c		\
			src/bultins/env_bultins.c		\
			src/bultins/exit_bultin.c		\
			src/bultins/alias_bultin.c		\
			src/bultins/alias_bultin_two.c	\
			src/bultins/set_builtin.c		\
			src/bultins/set_builtin_two.c	\
			src/bultins/unset_builtin.c		\

COMMAND_CLASSIC	=	src/command_classic/execute_classic.c		\
					src/command_classic/execute_classic_verif.c	\
					src/command_classic/execute_pipe.c			\
					src/command_classic/execute_redirection.c	\

ENV	=		src/env/env_utils.c			\
			src/env/get_change_env.c	\

SHELL_GESTION	=	src/shell/free_shell.c				\
					src/shell/prompt_action.c			\
					src/shell/shell_loop.c				\
					src/shell/shell_setup.c				\
					src/shell/auto_completion.c			\
					src/shell/draw_auto_completion.c	\

HIST	=	src/hist_and_prompt/my_hist_list_create.c			\
			src/hist_and_prompt/my_hist_list_tools.c			\
			src/hist_and_prompt/my_hist_noad_create.c			\
			src/hist_and_prompt/my_line_list_add.c				\
			src/hist_and_prompt/my_line_list_change_hist.c		\
			src/hist_and_prompt/my_line_list_create.c			\
			src/hist_and_prompt/my_line_list_cursor.c			\
			src/hist_and_prompt/my_line_list_new_line_check.c	\
			src/hist_and_prompt/my_line_list_tools.c			\
			src/hist_and_prompt/my_line_noad_create.c			\
			src/hist_and_prompt/prompt_manager.c				\
			src/hist_and_prompt/char_manage.c					\

STACK	=	src/stack/clean_stack.c						\
			src/stack/execute_stack.c					\
			src/stack/execute_classic.c					\
			src/stack/execute_and_or_stack.c			\
			src/stack/fill_stack_classic.c				\
			src/stack/fill_stack_pipe.c					\
			src/stack/fill_stack_and_or.c				\
			src/stack/fill_stack_redirection.c			\
			src/stack/fill_stack_redirection_part_two.c	\
			src/stack/fill_stack_separators.c			\
			src/stack/return_position_stack.c			\
			src/stack/verif_and_or_stack.c				\

UTILS	=	src/utils/my_strtok.c					\
			src/utils/utils.c						\
			src/utils/transform_command.c			\
			src/utils/manage_str.c						\

SRC	=		$(BULTINS)				\
			$(COMMAND_CLASSIC)		\
			$(ENV)					\
			$(SHELL_GESTION)		\
			$(STACK)				\
			$(UTILS)				\
			$(FEATURES)				\
			$(HIST)					\
			src/main.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-I./include/ -g

SRC_T	=	tests/test.c 			\
			$(BULTINS)				\
			$(COMMAND_CLASSIC)		\
			$(ENV)					\
			$(SHELL_GESTION)		\
			$(HIST)					\
			$(STACK)				\
			$(UTILS)				\
			$(FEATURES)				\

TEST_N	=	unit_tests

LIB	=	-L./lib/ -lmy

TFLAGS	=	-lcriterion --coverage -I include/

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean:
	rm -f $(OBJ)

clean_test:
	rm -f unit_tests
	rm -f *.gcno
	rm -f *.gcda

fclean: clean clean_test
	$(MAKE) -C lib/my fclean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all: $(NAME) clean

dbg: CFLAGS += -g
dbg: re
