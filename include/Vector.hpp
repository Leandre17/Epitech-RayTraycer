/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** Vector
*/

#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

namespace Math {
    class Point3D;
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(Vector3D &&) = default;
            Vector3D(const Vector3D &) = default;
            Vector3D &operator=(Vector3D &&) = default;
            Vector3D &operator=(const Vector3D &) = default;
            Vector3D(const Point3D &);
            Vector3D operator=(const Point3D &);
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
    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(Point3D &&) = default;
            Point3D(const Point3D &) = default;
            Point3D(const Vector3D &o) : X{o.X}, Y{o.Y}, Z{o.Z} {};
            // Point3D &operator=(const Vector3D &o) {
            //     this->X = o.X;
            //     this->Y = o.Y;
            //     this->Z = o.Z;
            //     return (Point3D){o.X, o.Y, o.Z};
            // };
            Point3D& operator=(const Vector3D &o) {
                this->X = o.X;
                this->Y = o.Y;
                this->Z = o.Z;
                return *this;
            };
            Point3D &operator=(Point3D &&) = default;
            Point3D &operator=(const Point3D &) = default;
            ~Point3D() = default;
            Point3D operator+(Vector3D);
            Point3D operator+=(Vector3D);
            Point3D operator-(Point3D);
            double length();
            Vector3D to_vector() const {
                return Vector3D(X, Y, Z);
            }
            double X;
            double Y;
            double Z;
    };
}

double dot(Math::Vector3D a, Math::Vector3D b);
