##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

all: ncurse sdl sfml

ncurse:
	@make -C Ncurse --no-print-directory

sdl:
	@make -C Sdl --no-print-directory

sfml:
	@make -C Sfml --no-print-directory

clean:
	@make -C Ncurse clean --no-print-directory
	@make -C Sdl clean --no-print-directory
	@make -C Sfml clean --no-print-directory

fclean: clean
	@make -C Ncurse fclean --no-print-directory
	@make -C Sdl fclean --no-print-directory
	@make -C Sfml fclean --no-print-directory

re: fclean all

dbg:
	@make -C Ncurse dbg --no-print-directory
	@make -C Sdl dbg --no-print-directory
	@make -C Sfml dbg --no-print-directory

.PHONY: all games ncurse sdl sfml clean fclean re dbg