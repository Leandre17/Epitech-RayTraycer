/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Primitives
*/


#include "Primitives.hpp"

RayTracer::Sphere::Sphere(Math::Point3D point, double radius): center{point}, radius{radius} {}

double dot(Math::Vector3D a, Math::Vector3D b) {
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

bool RayTracer::Sphere::hits(RayTracer::Ray ray) {
    double a = std::pow(ray.direction.length(), 2);
    double b = 2 * dot(ray.direction, ray.origin - center);
    double c = std::pow((ray.origin - center).length(), 2) - std::pow(radius, 2);

    double discriminant = std::pow(b, 2) - 4 * a * c;

    if (discriminant >= 0) {
        return true;
    } else {
        return false;
    }
}

RayTracer::Plane::Plane(Math::Point3D pointa, Math::Point3D pointb, Math::Point3D pointc, Math::Point3D pointd): pointa{pointa}, pointb{pointb}, pointc{pointc}, pointd{pointd} {}

bool RayTracer::Plane::hits(RayTracer::Ray ray) {
    
}