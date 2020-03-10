##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/pong.c	\
		src/print_descr.c	\

TESTS	=	src/pong.c	\
		src/print_descr.c	\
		tests/test_pong.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS	=	-W -Wall -I include/

LDFLAGS	=	-lm

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(CC) -o $(EXECTESTS) $(TESTS) $(CFLAGS) $(LDFLAGS) $(UNITFLAGS)
	./$(EXECTESTS) && gcovr --branches --exclude tests/

clean:
	rm -f *~
	rm -f $(OBJ)
	rm -f *gc*

fclean: clean
	rm -f $(NAME)
	rm -f $(EXECTESTS)

re:	fclean all

.PHONY: all clean fclean re
