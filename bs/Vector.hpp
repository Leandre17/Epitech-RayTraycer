/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** Vector
*/

#pragma once
#include <cmath>

namespace Math {
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(Vector3D &&) = default;
            Vector3D(const Vector3D &) = default;
            Vector3D &operator=(Vector3D &&) = default;
            Vector3D &operator=(const Vector3D &) = default;
            ~Vector3D() = default;

            Vector3D operator+(Vector3D);
            Vector3D operator+=(Vector3D);
            Vector3D operator-(Vector3D);
            Vector3D operator-=(Vector3D);
            Vector3D operator*(Vector3D);
            Vector3D operator*=(Vector3D);
            Vector3D operator/(Vector3D);
            Vector3D operator/=(Vector3D);
            Vector3D operator*(double o);
            Vector3D operator*=(double o);
            Vector3D operator/(double o);
            Vector3D operator/=(double o);
            double length();
            double dot(Vector3D);
            
            double X;
            double Y;
            double Z;
    };
}
