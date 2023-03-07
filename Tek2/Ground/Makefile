##
## EPITECH PROJECT, 2022
## Ground
## File description:
## Makefile
##

all: ground

ground:
	cp src/groundhog.py ./groundhog
	chmod 754 groundhog

clean:
	rm -f groundhog

fclean: clean

re: fclean all

tests_run:
	coverage run --source=src/ -m pytest && coverage report

.PHONY: all ground clean fclean re tests_run