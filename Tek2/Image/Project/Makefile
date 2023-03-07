##
## EPITECH PROJECT, 2022
## wolfram
## File description:
## Makefile
##

NAME    =	imageCompressor

all:
	stack build
	cp `stack path --local-install-root`/bin/Image-Compressor-exe $(NAME)

clean:
	find -name *.hi -delete
	find -name *.o -delete

fclean:	clean
	rm -f ../$(NAME)

re:	fclean  all
