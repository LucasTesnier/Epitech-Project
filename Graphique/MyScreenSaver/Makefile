##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

CFLAGS 	=	-I include/

TUSRC	=	src/adn_monster.c\
		src/bwing_ball.c\
		src/complementary_functions.c\
		src/my_pixel_function.c\
		src/my_random_pixel.c\
		src/random_laser.c\
		src/bubble_master.c\
		src/complementary_function.c\
		src/fractale.c\
		src/mouse_catcher.c\
		src/my_pixel_function_two.c\
		src/my_screen_saver.c

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy -lm -lcsfml-graphics

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run:
	gcc -o unit_tests $(CFLAGS) $(TUSRC) tests/test.c -L./lib/ -lmy -lm \
	-lcsfml-graphics -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

all:	$(NAME) clean
