/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Rectangle3D {
    public:
        Rectangle3D() = default;
        Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
        Rectangle3D(Rectangle3D &&) = default;
        Rectangle3D(const Rectangle3D &) = default;
        Rectangle3D &operator=(Rectangle3D &&) = default;
        Rectangle3D &operator=(const Rectangle3D &) = default;
        ~Rectangle3D() = default;
        Math::Point3D pointAt(double u, double v);
    private:
        Math::Point3D origin;
        Math::Vector3D bottom_side;
        Math::Vector3D left_side;
};