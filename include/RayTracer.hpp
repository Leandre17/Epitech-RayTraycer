/*
** EPITECH PROJECT, 2023
** bsraytraycer
** File description:
** RayTracer
*/

#pragma once
#include "Camera.hpp"
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
}


