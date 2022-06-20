##
## EPITECH PROJECT, 2021
## ex00
## File description:
## Makefile
##

POOL = -std=gnu17 -Wall -Wextra

CFLAGS = -Wall -Wextra -Wpedantic -g3 -I./include -lm

NCURSES = -lncurses

SRC	=	z.c \

OBJ 	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	z

all:	$(NAME)

$(NAME):	$(OBJ)
		@gcc -o $(NAME) $(SRC) $(POOL)
		@rm -f *.o source/*.o library/*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all re clean fclean