/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Color
*/

#include "Color.hpp"

RayTracer::Color::Color(double red, double green, double blue) : red{(int)red}, green{(int)green}, blue{(int)blue} {}
RayTracer::Color::Color(int red, int green, int blue) : red{red}, green{green}, blue{blue} {}


int RayTracer::Color::getRed() const {return red;}
int RayTracer::Color::getGreen() const {return green;}
int RayTracer::Color::getBlue() const {return blue;}

std::ostream &operator<<(std::ostream &a, const RayTracer::Color &b) {
    return a << b.getRed() << " " << b.getGreen() << " " << b.getBlue() << "\n";
}
