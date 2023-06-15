##
## EPITECH PROJECT, 2023
## B-PSU-100-RUN-1-1-bsnavy-hugo.payet
## File description:
## Makefile
##

SRC	=	$(shell find ./src -name "*.c")

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	jason_parser

CFLAGS 	=	-W -Wall -Wextra -Werror -g3 -I./include/

MEMORY_FLAG	=	-Wpadded

TEST_BIN =	unit_tests

TEST_SRC =	$(shell find ./lib -name "*.c" -not -name "sh.c") \
	$(shell find ./tests -name "*.c")

all	:	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(MEMORY_FLAG)

opt	:	$(OBJ)
	make all  $(MEMORY_FLAG)

clean	:
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.c~

fclean	: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re	: fclean all

valgrind:
	valgrind ./$(NAME)