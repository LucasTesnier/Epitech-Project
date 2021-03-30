##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-I include/

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run:
	$(MAKE) -C tests/
	./tests/test_bistro

all:	$(NAME) clean
