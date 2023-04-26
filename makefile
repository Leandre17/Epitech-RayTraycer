##
## EPITECH PROJECT, 2023
## raytraycer
## File description:
## Makefile
##

SRC =	src/main.cpp \
	src/algo/Vector.cpp	\
	src/algo/Matrix.cpp	\
	src/camera/Camera.cpp \
	src/camera/Ray.cpp \
	src/camera/Scene.cpp \
	src/image/Image.cpp	\
	src/image/Color.cpp	\
	src/light/ALight.cpp	\
	src/light/PointLight.cpp	\
	src/object/AObject.cpp	\
	src/object/Plane.cpp	\
	src/object/Sphere.cpp	\
	src/gtfm.cpp

NAME = raytracer

CXXFLAGS	=	-Wall -Wextra -std=c++20

CPPFLAGS	= -I ./include -I ./include/image -I ./include/algo -I ./include/camera -I ./include/object -I ./include/light

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