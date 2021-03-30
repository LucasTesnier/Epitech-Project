##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

all:
	$(MAKE) -C ./lib/my
	$(MAKE) -C antman/
	$(MAKE) -C giantman/

clean:
	$(MAKE) clean -C antman/
	$(MAKE) clean -C giantman/

fclean: clean
	$(MAKE) fclean -C ./lib/my/
	$(MAKE) fclean -C antman/
	$(MAKE) fclean -C giantman/

tests_run:
	$(MAKE) -C ./lib/my
	$(MAKE) tests_run -C antman/
	$(MAKE) tests_run -C giantman/
	./antman/unit_tests
	./giantman/unit_tests
	gcovr --exclude antman/tests/
	gcovr --exclude antman/tests/ --branches

re: fclean all
