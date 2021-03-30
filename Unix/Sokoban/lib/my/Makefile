##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compil the librairies
##

SRC	=	my_compute_power_rec.c\
		my_getnbr_base.c\
		my_getnbr.c\
		my_putchar.c\
		my_putnbr_base.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_strdup.c\
		my_strlen.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_isnum.c\
		my_memset_char.c\
		my_calloc_char.c\
		my_memset_int.c\
                my_calloc_int.c\
		my_str_isnum.c\
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
	rm ../$(NAME)

re: fclean all
