##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

CC		=	g++

BASIC_COMPONENT	=	src/nts/basicComponent/Input/Input.cpp		\
					src/nts/basicComponent/Output/Output.cpp	\
					src/nts/basicComponent/True/True.cpp		\
					src/nts/basicComponent/False/False.cpp		\
					src/nts/basicComponent/Clock/Clock.cpp		\
					src/nts/AComponent.cpp

OTHER_COMPONENT	=	src/nts/otherComponent/4001/C4001.cpp		\
					src/nts/otherComponent/4011/C4011.cpp		\
					src/nts/otherComponent/4030/C4030.cpp		\
					src/nts/otherComponent/4069/C4069.cpp		\
					src/nts/otherComponent/4071/C4071.cpp		\
					src/nts/otherComponent/4081/C4081.cpp

ERROR	=	src/nts/Error/Error.cpp		\

SYSTEM	=	src/nts/System/System.cpp

USERCOMMUNICATION	=	src/nts/UserCommunication/UserCommunication.cpp

PARSER	=	src/nts/FileLoader/FileLoader.cpp	\
			src/nts/Parser/Parser.cpp

SRC		=	src/main.cpp				\
			src/start.cpp				\
			$(BASIC_COMPONENT)			\
			$(OTHER_COMPONENT)			\
			$(SYSTEM)					\
			$(ERROR)					\
			$(USERCOMMUNICATION)		\
			$(PARSER)

TEST_FILES	=	tests/Tests/testsComponents/testsComponents.cpp					\
				tests/Tests/testsParser/testsParser.cpp							\
				tests/Tests/testsUserCommunication/testsUserCommunication.cpp

SRC_T	=	$(BASIC_COMPONENT)								\
			$(OTHER_COMPONENT)								\
			$(SYSTEM)										\
			$(ERROR)										\
			$(USERCOMMUNICATION)							\
			$(PARSER)										\
			$(TEST_FILES)

OBJ		=	$(SRC:.cpp=.o)

OBJ_T	=	$(SRC_T:.cpp=.o)

NAME	=	nanotekspice

CXXFLAGS	= -std=c++20 -Wall -Wextra -Werror -I src/nts/

TEST_N	=	unit_tests

TCFLAGS	=   -std=c++17 -Wall -Wextra -Werror -lcriterion --coverage -I src/nts/
TLDFLAGS	=	-lcriterion --coverage -I src/nts/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_T)
	find . -name '*~' -delete -o -name '#*#' -delete -o -name '*.gcno' \
		-delete -o -name -'*.gcdo' -delete -o -name '*.gcda' -delete

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_N)
	rm -f src/*.o

tests_run:	CXXFLAGS = $(TCFLAGS)
tests_run: 	fclean $(OBJ_T)
	$(CC) -o $(TEST_N) $(OBJ_T) $(TLDFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

re: fclean all

dbg: CXXFLAGS += -g
dbg: re
