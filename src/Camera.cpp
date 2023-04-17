/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#include "RayTracer.hpp"

Rectangle3D::Rectangle3D(Math::Point3D _origin, Math::Vector3D _bottom_side, Math::Vector3D _left_side) {
    left_side = _left_side;
    bottom_side = _bottom_side;
    origin = _origin;
}

Math::Point3D Rectangle3D::pointAt(double u, double v) {
    Math::Point3D result{u, v, 1};
    return result;
}

RayTracer::Ray RayTracer::Camera::ray(double u ,double v) {
    Ray tmp{};
    tmp.origin = this->origin;
    tmp.direction = screen.pointAt(u, v);
    return tmp;
}
