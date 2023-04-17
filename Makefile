##
## EPITECH PROJECT, 2023
## B-OOP-400-BDX-4-1-raytracer-johanna.bureau
## File description:
## Makefile
##

SRC =	src/main.cpp \
	src/Point.cpp	\
	src/Vector.cpp	\
	src/camera.cpp

NAME = raytracer

CXXFLAGS	=	-Wall -Wextra -std=c++20 -lsfml-window -lsfml-graphics -lsfml-system

CPPFLAGS	= -I ./include

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

debug: fclean
debug: CXXFLAGS += -ggdb3
debug: all

.PHONY: all clean fclean re debug