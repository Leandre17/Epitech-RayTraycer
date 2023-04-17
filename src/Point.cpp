/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** Point
*/

#include "Vector.hpp"
using namespace Math;

Point3D::Point3D() : X{0}, Y{0}, Z{0} {}
Point3D::Point3D(double x, double y, double z) : X{x}, Y{y}, Z{z} {}

Point3D Point3D::operator+(Vector3D o) { return {this->X + o.X, this->Y + o.Y, this->Z + o.Z}; }
Point3D Point3D::operator+=(Vector3D o) {
    this->X += o.X;
    this->Y += o.Y;
    this->Z += o.Z;
    return *this;
}

Point3D Point3D::operator-(Point3D o) { return {this->X - o.X, this->Y - o.Y, this->Z - o.Z}; }

double Point3D::length() {
    double distance_care = std::pow(X, 2) + std::pow(Y, 2) + std::pow(Z, 2);
    return std::sqrt(distance_care);
}
