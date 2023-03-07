##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

CC		=	g++

SRC		=	Nibbler.cpp		\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	../../../lib/arcade_nibbler.so

CXXFLAGS	= -std=c++20 -Wall -Wextra -Werror -I ./ -I ../ -I ../.. -fPIC -shared -ldl -fno-gnu-unique

END	=	"\033[00m"

GREEN	=	"\033[0;32m"

CYAN	=	"\033[1;36m"

RED	=	"\033[5;31m"

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) && \
	echo -e $(GREEN) "[OK]"$(CYAN)" BUILD : arcade_nibbler.so" $(END) || \
	echo -e $(RED) "[NOK]" $(CYAN) $(NAME) $(END)

clean:
	@rm -f $(OBJ) && \
	echo -e $(GREEN) "[OK] clean"$(CYAN) $(OBJ) $(END) || \
	echo -e $(RED) "[NOK] clean" $(CYAN) $(OBJ) $(END)
	@find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' \
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	@rm -f $(NAME) && \
	echo -e $(GREEN) "[OK] fclean"$(CYAN) arcade_nibbler.so $(END) || \
	echo -e $(RED) "[NOK] fclean" $(CYAN) arcade_nibbler.so $(END)
	@rm -f *.o

re: fclean all

dbg: CXXFLAGS += -g
dbg: re

.PHONY: all clean fclean re dbg