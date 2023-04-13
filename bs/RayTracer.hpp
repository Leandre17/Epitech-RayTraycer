/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#pragma once
#include "Point.hpp"
#include "camera.hpp"
#include <iostream>

namespace RayTracer {
    class Ray {
        public:
            Ray() = default;
            Ray(Math::Point3D, Math::Vector3D);
            Ray(Ray &&) = default;
            Ray(const Ray &) = default;
            Ray &operator=(Ray &&) = default;
            Ray &operator=(const Ray &) = default;
            ~Ray() = default;
            Math::Point3D origin;
            Math::Vector3D direction;
    };
    Ray::Ray(Math::Point3D point, Math::Vector3D vct): origin{point}, direction{vct} {}
    
    class Sphere {
        public :
            Sphere(Math::Point3D, double);
            bool hits(RayTracer::Ray);
            ~Sphere() = default;
        private:
            Math::Point3D center;
            double radius;
    };
    Sphere::Sphere(Math::Point3D point, double radius): center{point}, radius{radius} {}
    bool Sphere::hits(RayTracer::Ray rayon) {
        double a = std::pow(rayon.direction.X, 2) + std::pow(rayon.direction.Y, 2) + std::pow(rayon.direction.Z, 2);
        double b = 2*rayon.origin.X*rayon.direction.X+2*rayon.origin.Y*rayon.direction.Y+2*rayon.origin.Z*rayon.direction.Z;
        double c = std::pow(rayon.origin.X, 2) + std::pow(rayon.origin.Y, 2) + std::pow(rayon.origin.Z, 2) - std::pow(this->radius, 2);

        double d = std::pow(b, 2) - 4*a*c;
        std::cout << "rayon direction : " << rayon.direction.X << ", " << rayon.direction.Y << ", " << rayon.direction.Z << "\n";
        std::cout << "a, b, c : " << a << ", " << b << ", " << c << "\n";
        if (d >= 0) {
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
        tmp.origin = screen.pointAt(u, v);
        tmp.direction = tmp.origin;
        return tmp;
    }
}


