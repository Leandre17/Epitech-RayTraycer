/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** Point
*/

#pragma once
#include "Vector.hpp"

namespace Math {

    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(Point3D &&) = default;
            Point3D(const Point3D &) = default;
            Point3D &operator=(Point3D &&) = default;
            Point3D &operator=(const Point3D &) = default;
            ~Point3D() = default;
            Point3D operator+(Vector3D);
            // Point3D operator+=(Point3D);
            // Point3D operator-(Point3D);
            // Point3D operator-=(Point3D);
            // Point3D operator*(Point3D);
            // Point3D operator*=(Point3D);
            // Point3D operator/(Point3D);
            // Point3D operator/=(Point3D);
            // Point3D operator*(double o);
            // Point3D operator*=(double o);
            // Point3D operator/(double o);
            // Point3D operator/=(double o);
            double X;
            double Y;
            double Z;
    };
}