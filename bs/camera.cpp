/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#include "camera.hpp"

Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side)
    : left_side{left_side}, bottom_side{bottom_side}, origin{origin} {}

Math::Point3D Rectangle3D::pointAt(double u, double v) {
    Math::Point3D result{u, v, 0};
    return result;
}