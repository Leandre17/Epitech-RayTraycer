/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** Vector
*/

#include "Vector.hpp"
using namespace Math;

Vector3D::Vector3D() : X{0}, Y{0}, Z{0} {}
Vector3D::Vector3D(double x, double y, double z) : X{x}, Y{y}, Z{z} {}

Vector3D::Vector3D(const Point3D &o) {
    this->X = o.X;
    this->Y = o.Y;
    this->Z = o.Z;
}
Vector3D Vector3D::operator=(const Point3D &o) {
    this->X = o.X;
    this->Y = o.Y;
    this->Z = o.Z;
    return (Vector3D){o.X, o.Y, o.Z};
}

double Vector3D::length() {
    double distance_care = std::pow(X, 2) + std::pow(Y, 2) + std::pow(Z, 2);
    return std::sqrt(distance_care);
}

Vector3D Vector3D::operator+(Vector3D o) {
    Vector3D tmp{this->X + o.X, this->Y + o.Y, this->Z + o.Z};
    return tmp;
}

Vector3D Vector3D::operator+=(Vector3D o) {
    this->X += o.X;
    this->Y += o.Y;
    this->Z += o.Z;
    return *this;
}

Vector3D Vector3D::operator-(Vector3D o) {
    Vector3D tmp{this->X - o.X, this->Y - o.Y, this->Z - o.Z};
    return tmp;
}

Vector3D Vector3D::operator-=(Vector3D o) {
    this->X -= o.X;
    this->Y -= o.Y;
    this->Z -= o.Z;
    return *this;
}

Vector3D Vector3D::operator*(Vector3D o) {
    Vector3D tmp{this->X * o.X, this->Y * o.Y, this->Z * o.Z};
    return tmp;
}

Vector3D Vector3D::operator*=(Vector3D o) {
    this->X *= o.X;
    this->Y *= o.Y;
    this->Z *= o.Z;
    return *this;
}

Vector3D Vector3D::operator/(Vector3D o) {
    Vector3D tmp{this->X / o.X, this->Y / o.Y, this->Z / o.Z};
    return tmp;
}

Vector3D Vector3D::operator/=(Vector3D o) {
    this->X /= o.X;
    this->Y /= o.Y;
    this->Z /= o.Z;
    return *this;
}

Vector3D Vector3D::operator*(double o) {
    Vector3D tmp{this->X * o, this->Y * o, this->Z * o};
    return tmp;
}

Vector3D Vector3D::operator/(double o) {
    Vector3D tmp{this->X / o, this->Y / o, this->Z / o};
    return tmp;
}

Vector3D Vector3D::operator/=(double o) {
    this->X /= o;
    this->Y /= o;
    this->Z /= o;
    return *this;
}

Vector3D Vector3D::operator*=(double o) {
    this->X *= o;
    this->Y *= o;
    this->Z *= o;
    return *this;
}

double Vector3D::dot(Vector3D o) {
    double result = (this->X * o.X) + (this->Y * o.Y) + (this->Z * o.Z);
    return result;
}
