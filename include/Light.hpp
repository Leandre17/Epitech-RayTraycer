/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_
#include "Vector.hpp"

class Light {
    public:
        Light() = default;
        Light(double ambient, double diffuse, Math::Point3D point);
        ~Light() = default;

    private:
        double ambient;
        double diffuse;
        Math::Point3D origin;
};

#endif /* !LIGHT_HPP_ */
