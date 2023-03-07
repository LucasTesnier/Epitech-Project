##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

MAIN	=	src/main.c

FILES	=	

SRC	=	$(MAIN)		\
		$(FILES)

OBJ	=	$(SRC:.c=.o)

NAME	=	step2

CFLAGS	=	-Wall -Wextra -Wshadow

all: $(NAME)

$(NAME):	CFLAGS += -I include/
$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' \
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

dbg: CFLAGS += -g
dbg: re
