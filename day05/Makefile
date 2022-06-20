##
## EPITECH PROJECT, 2021
## ex00
## File description:
## Makefile
##

POOL = -std=gnu17 -Wall -Wextra

CFLAGS = -Wall -Wextra -Wpedantic -g3 -I./include -lm

NCURSES = -lncurses

SRC	=	string.c \
		string_assign.c \
		string_append.c \
		string_at.c \
		string_clear.c \
		string_length.c \
		string_compare.c \
		string_copy.c \
		string_cstr.c \
		string_empty.c \
		string_find.c \
		string_insert.c \
		string_to_int.c \
		string_split.c \
		string_print.c \

OBJ 	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
		@gcc -c $(SRC) $(POOL)
		@ar rc $(NAME) $(OBJ)
		@rm -f *.o source/*.o library/*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all re clean fclean