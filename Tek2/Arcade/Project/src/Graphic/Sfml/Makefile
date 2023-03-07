##
## EPITECH PROJECT, 2020
## arcade
## File description:
## for arcade
## Makfile

SRC	=	Sfml.cpp

NAME	=	../../../lib/arcade_sfml.so

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-std=c++20 -I ../ -I ../.. -W -Wall -Wextra -Wshadow -lsfml-graphics -lsfml-window -lsfml-system -shared -fPIC -fno-gnu-unique

CC	=	g++

END	=	"\033[00m"

GREEN	=	"\033[0;32m"

CYAN	=	"\033[1;36m"

RED	=	"\033[5;31m"

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) && \
	echo -e $(GREEN) "[OK]"$(CYAN)" BUILD : arcade_sfml.so" $(END) || \
	echo -e $(RED) "[NOK]" $(CYAN) $(NAME) $(END)

tests_run:
	make -C tests/
	./tests/unit_tests

clean:
	@rm -f $(OBJ) && \
	echo -e $(GREEN) "[OK] clean"$(CYAN) $(OBJ) $(END) || \
	echo -e $(RED) "[NOK] clean" $(CYAN) $(OBJ) $(END)
	@find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' \
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	@rm -f $(NAME) && \
	echo -e $(GREEN) "[OK] fclean"$(CYAN) arcade_sfml.so $(END) || \
	echo -e $(RED) "[NOK] fclean" $(CYAN) arcade_sfml.so $(END)
	@rm -f *.o

re:		fclean all

dbg:		CXXFLAGS += -g

dbg:		re