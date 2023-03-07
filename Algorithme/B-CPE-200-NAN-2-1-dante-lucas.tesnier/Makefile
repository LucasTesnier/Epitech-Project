##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

TFLAGS	=	-lcriterion --coverage -I generator/include

TEST_N 	=	unit_tests

SRC_T	=	tests/test.c\
			generator/src/lab_draw.c\
			generator/src/value_gestion.c\
			generator/src/wall_modification.c\
			generator/src/setup_lab.c

all:
	$(MAKE) -C generator/
	$(MAKE) -C solver/

clean:
	$(MAKE) clean -C generator/
	$(MAKE) clean -C solver/

fclean: clean
	$(MAKE) fclean -C generator/
	$(MAKE) fclean -C solver/

re: fclean all

tests_run:
	gcc -o $(TEST_N) $(SRC_T) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

