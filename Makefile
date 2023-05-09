##
## EPITECH PROJECT, 2023
## raytraycer
## File description:
## Makefile
##

SRC_PARSING	=	src/parsing/parsing_obj.cpp

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
	src/object/Cylindre.cpp	\
	src/object/Cone.cpp	\
	src/object/Transform.cpp	\
	src/design_patern/Factory.cpp	\
	src/design_patern/Builder.cpp		\
	src/design_patern/Director.cpp		\
	${SRC_PARSING}

NAME = raytracer

CXXFLAGS	=	-Wall -Wextra -std=c++20 -lconfig++

CPPFLAGS	= -I ./include -I ./include/image -I ./include/algo -I ./include/camera -I ./include/design_patern -I ./include/object -I ./include/light -I ./include/parsing

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
