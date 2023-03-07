##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

NMMAIN	=	Nm/src/main.c

NMFILES	=	Nm/src/sym.c				\
			Nm/src/nm_gestion.c			\
			Nm/src/char_modification.c	\
			Nm/src/symbol_type.c

NMSRC	=	$(NMMAIN)	\
			$(NMFILES)

NMOBJ	=	$(NMSRC:.c=.o)

NMNAME	=	my_nm

OBJMAIN	=	Objdump/src/main.c

OBJFILES	=	Objdump/src/objdump_gestion.c		\
				Objdump/src/is_valid_extension.c	\
				Objdump/src/objdump_data.c			\
				Objdump/src/data_traitment_64.c		\
				Objdump/src/data_traitment_32.c

OBJSRC	=	$(OBJMAIN)	\
			$(OBJFILES)

OBJOBJ	=	$(OBJSRC:.c=.o)

OBJNAME	=	my_objdump

CFLAGS	=	-Wall -Wextra -Wshadow

NMSRC_T	=	$(NMFILES)							\
			tests/Nm/char_modification_test.c	\
			tests/Nm/sym_test.c					\
			tests/Nm/nm_gestion_test.c

NMTEST_N	=	nm_unit_tests

OBJSRC_T	=	$(OBJFILES)								\
				tests/Objdump/objdump_gestion_test.c

OBJTEST_N	=	obj_unit_tests

TFLAGS	=	-lcriterion --coverage

all: nm objdump

nm:	CFLAGS += -I Nm/include/
nm: $(NMOBJ)
	gcc -o $(NMNAME) $(NMOBJ)

objdump:	CFLAGS += -I Objdump/include/
objdump: $(OBJOBJ)
	gcc -o $(OBJNAME) $(OBJOBJ)

clean:
	rm -f $(NMOBJ)
	rm -f $(OBJOBJ)
	find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' \
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	rm -f $(NMNAME)
	rm -f $(OBJNAME)
	rm -f Nm/src/*.o
	rm -f Objdump/src/*.o

nmtests: TFLAGS += -I Nm/include/
nmtests:
	gcc -o $(NMTEST_N) $(NMSRC_T) $(TFLAGS)
	./$(NMTEST_N)

objtests: TFLAGS += -I Objdump/include/
objtests:
	gcc -o $(OBJTEST_N) $(OBJSRC_T) $(TFLAGS)
	./$(OBJTEST_N)

tests_run: nmtests objtests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
	

re: fclean all

dbg: CFLAGS += -g
dbg: re
