##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD02-lucas.tesnier
## File description:
## Makefile
##

NAME	=	wolfram

CC	=	stack

$(NAME):
	$(CC) build --ghc-options=-O2
	cp `stack path --local-install-root`/bin/Wolframe-exe ./$(NAME)

clean:
	$(CC) clean

fclean: clean
	rm -f ./$(NAME)

re: fclean all

all:	$(NAME)