##
## EPITECH PROJECT, 2021
## ex00
## File description:
## Makefile
##

POOL = -std=c++20 -Wall -Wextra -Werror

CFLAGS = -Wall -Wextra -Wpedantic -g3 -I./include -lm

NCURSES = -lncurses

SRC	=	main.cpp \

OBJ 	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(SRC) $(POOL)
		@rm -f *.o source/*.o library/*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all re clean fclean