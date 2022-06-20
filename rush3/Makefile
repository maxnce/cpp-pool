##
## EPITECH PROJECT, 2021
## ex00
## File description:
## Makefile
##

POOL = -std=c++20 -Wall -Wextra

CFLAGS = -Wall -Wextra -Wpedantic -g3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NCURSES = -lncurses

SRC     =       source/main.cpp \
				source/Mode.cpp \
				source/Core.cpp \
				source/Sys.cpp \
				source/Hostname.cpp \
				source/DateTime.cpp \
				source/Kernel.cpp \
				source/Monitor.cpp \
				source/Ram.cpp \
				source/Parse.cpp \
				source/ListModul.cpp \
				source/Gpu.cpp \

OBJ     =       $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME    =       MyGKrellm

all:    $(NAME)

$(NAME):		$(OBJ)
				@g++ -o $(NAME) $(SRC) $(CFLAGS) $(POOL) $(NCURSES)
				@rm -f *.o source/*.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
