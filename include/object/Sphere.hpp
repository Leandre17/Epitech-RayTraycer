/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include "IObject.hpp"
#include "gtfm.hpp"

namespace RayTracer {
    class Sphere : public AObject {
        public:
            Sphere() = default;
            ~Sphere() override = default;

            // Override the function to test for intersections.
            virtual bool TestIntersection(const RayTracer::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal,
                                        qbVector<double> &localColor) override;
    };
} // namespace RayTracer
