##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

all: graphicals games core

games:
	@make -C src/Game --no-print-directory

core:
	@make -C src/Core --no-print-directory

graphicals:
	@make -C src/Graphic --no-print-directory

clean:
	@make -C src/Game clean --no-print-directory
	@make -C src/Core clean --no-print-directory
	@make -C src/Graphic clean --no-print-directory

fclean: clean
	@make -C src/Game fclean --no-print-directory
	@make -C src/Core fclean --no-print-directory
	@make -C src/Graphic fclean --no-print-directory

re: fclean all

dbg:
	@make -C src/Game dbg --no-print-directory
	@make -C src/Core dbg --no-print-directory
	@make -C src/Graphic dbg --no-print-directory

.PHONY: all games graphicals core clean fclean re dbg