##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

all: nibbler pacman

nibbler:
	@make -C Nibbler --no-print-directory

pacman:
	@make -C Pacman --no-print-directory

clean:
	@make -C Nibbler clean --no-print-directory
	@make -C Pacman clean --no-print-directory

fclean: clean
	@make -C Nibbler fclean --no-print-directory
	@make -C Pacman fclean --no-print-directory

re: fclean all

dbg:
	@make -C Nibbler dbg --no-print-directory
	@make -C Pacman dbg --no-print-directory

.PHONY: all nibbler pacman clean fclean re dbg