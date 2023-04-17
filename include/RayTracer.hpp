/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#pragma once
#include "Vector.hpp"
#include "camera.hpp"
#include <iostream>

namespace RayTracer {
    class Ray {
        public:
            Ray() = default;
            Ray(Math::Point3D point, Math::Vector3D vct): origin{point}, direction{vct} {};
            Ray(Ray &&) = default;
            Ray(const Ray &) = default;
            Ray &operator=(Ray &&) = default;
            Ray &operator=(const Ray &) = default;
            ~Ray() = default;
            Math::Point3D origin;
            Math::Vector3D direction;
    };
    class Sphere {
        public :
            Sphere(Math::Point3D, double);
            bool hits(RayTracer::Ray);
            void translate(Math::Vector3D translate);
            ~Sphere() = default;
        private:
            Math::Point3D center;
            double radius;
    };
    Sphere::Sphere(Math::Point3D point, double radius): center{point}, radius{radius} {}

    double dot(Math::Vector3D a, Math::Vector3D b) {
        return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
    }
    bool Sphere::hits(RayTracer::Ray ray) {
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
    class Camera {
        public:
            Camera() = default;
            Camera(Math::Point3D origin, Rectangle3D screen) : origin{origin}, screen{screen} {}
            Camera(Camera &&) = default;
            Camera(const Camera &) = default;
            Camera &operator=(Camera &&) = default;
            Camera &operator=(const Camera &) = default;
            ~Camera() = default;
            Ray ray(double u ,double v);
        private:
            Math::Point3D origin;
            Rectangle3D screen;
    };
    Ray Camera::ray(double u ,double v) {
        Ray tmp{};
        tmp.origin = this->origin;
        tmp.direction = screen.pointAt(u, v);
        return tmp;
    }
}


