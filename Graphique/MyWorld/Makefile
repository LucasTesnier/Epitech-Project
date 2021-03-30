##
## EPITECH PROJECT, 2021
## makefile
## File description:
## desc
##

SRC	=	$(wildcard src/my_event/*.c) \
		$(wildcard src/my_game/*.c) \
		$(wildcard src/my_map/*.c) \
		$(wildcard src/my_sprite/*.c) \
		$(wildcard src/my_window/*.c) \
		$(wildcard src/my_draw/*.c) \
		$(wildcard src/my_text/*.c) \
		$(wildcard src/my_button/*.c) \
		$(wildcard src/my_shape/*.c) \
		$(wildcard src/my_cursor_tools/*.c) \
		main.c \

OBJ	=	$(SRC:.c=.o)

NAME=	my_world

CFLAGS	=	-I include -lcsfml-graphics -lm -lcsfml-system -L./lib/ -lmy -lgraphic -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/graphic
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' -delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean:	clean
	make fclean -C lib/my
	make fclean -C lib/graphic
	rm -f $(NAME)

re:	fclean all

dbg: CFLAGS += -g
dbg: re
