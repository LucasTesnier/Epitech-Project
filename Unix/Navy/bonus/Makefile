##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	:=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I include/ -L./lib/ -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: fclean $(NAME)

all:	$(NAME)

.PHONY = clean fclean re tests_run debug all
