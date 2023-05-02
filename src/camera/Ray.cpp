/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray
*/


#include "Ray.hpp"

RayTracer::Ray::Ray() {
    point1 = Vector3D{std::vector<double>{0.0, 0.0, 0.0}};
    point2 = Vector3D{std::vector<double>{0.0, 0.0, 1.0}};
    this->distance = point2 - point1;
}

RayTracer::Ray::Ray(const Vector3D &point1, const Vector3D &point2) {
    this->point1 = point1;
    this->point2 = point2;
    this->distance = point2 - point1;
}

Vector3D RayTracer::Ray::GetPoint1() const { return point1; }

Vector3D RayTracer::Ray::GetPoint2() const { return point2; }
