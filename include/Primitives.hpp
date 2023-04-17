/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Primitives
*/

#pragma once
#include "RayTracer.hpp"

namespace RayTracer {
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

    class Plane {
        public:
            Plane(Math::Point3D pointa, Math::Point3D pointb, Math::Point3D pointc, Math::Point3D pointd);
            bool hits(RayTracer::Ray);
            void translate(Math::Vector3D translate);
            ~Plane() = default;
        private:
            Math::Point3D pointa;
            Math::Point3D pointb;
            Math::Point3D pointc;
            Math::Point3D pointd;

    };
}
