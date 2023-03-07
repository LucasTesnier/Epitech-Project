##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

TFLAGS	:=	-I./asm/include/ -I./corewar/include/ -I./my -L./my -lmy -lcriterion --coverage

TEST_N 	:=	unit_tests

SRC_T	:=	tests/asm/test_asm.c			\
			tests/asm/test_null_objects.c	\
			tests/vm/test_vm.c				\
			tests/asm/test_insert.c \

SRC	:=	asm/src/asm.c	\
		asm/src/error_handling.c	\
		asm/src/read_file.c			\
		asm/src/parse_file.c			\
		asm/src/get_champions.c	\
		asm/src/insert_instruction.c	\
		asm/src/create_instruction.c	\
		asm/src/args_type/check_argument_type.c	\
		asm/src/insert_towrite.c \
		asm/src/utils/array_size.c	\
		asm/src/utils/get_program_size.c \
		asm/src/op.c	\
		asm/src/labels_manager/compute_label_offset.c \
		asm/src/get_node_size.c \
		asm/src/insert_size.c \
		asm/src/write_into_cor_file.c \
		asm/src/get_new_file_name.c \
		corewar/src/instructions/live.c				\
		corewar/src/instructions/ld.c				\
		corewar/src/instructions/convert_values.c	\
		corewar/src/instructions/parameters.c		\
		corewar/src/instructions/scheduling.c		\
		corewar/src/instructions/change_pc.c		\
		corewar/src/instructions/mem_write.c		\
		corewar/src/instructions/st.c				\
		corewar/src/instructions/add.c				\
		corewar/src/instructions/sub.c				\
		corewar/src/instructions/and.c				\
		corewar/src/instructions/or.c				\
		corewar/src/instructions/xor.c				\
		corewar/src/instructions/zjmp.c				\
		corewar/src/instructions/ldi.c				\
		corewar/src/instructions/sti.c				\
		corewar/src/instructions/fork.c				\
		corewar/src/instructions/lld.c				\
		corewar/src/instructions/lldi.c				\
		corewar/src/instructions/lfork.c			\
		corewar/src/instructions/aff.c				\
		corewar/src/champion_init.c						\
		corewar/src/flag_handling.c						\
		corewar/src/struct_init.c						\
		corewar/src/champ_mem_init.c					\
		corewar/src/champ_flags_handling.c				\
		corewar/src/memory_init.c						\
		corewar/src/unsigned_operations.c				\
		corewar/src/hexdump_display.c					\
		corewar/src/corewar_loop.c						\

all:
	$(MAKE) -C my/ -f Makefile -s
	$(MAKE) -C asm/ -f Makefile
	$(MAKE) -C corewar/ -f Makefile -s

asm:
	$(MAKE) -C my/ -f Makefile -s
	$(MAKE) -C asm/ -f Makefile -s

corewar:
	$(MAKE) -C my/ -f Makefile -s
	$(MAKE) -C corewar/ -f Makefile -s


clean:
	$(shell find -name "*.gcda" -delete)
	$(shell find -name "*.gcno" -delete)
	$(MAKE) clean -C my/
	$(MAKE) clean -C asm/ -f Makefile -s
	$(MAKE) clean -C corewar/ -f Makefile -s

fclean: clean
	$(MAKE) fclean -C my/
	$(MAKE) fclean -C asm/ -f Makefile -s
	$(MAKE) fclean -C corewar/ -f Makefile -s

re: fclean all

tests_run:
	$(MAKE) -C ./my
	gcc -o $(TEST_N) $(SRC) $(SRC_T) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean tests_run re asm corewar