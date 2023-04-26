/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plane
*/

#pragma once
#include "IObject.hpp"
#include "gtfm.hpp"

namespace RayTracer {
    class Plane : public AObject {
        public:
            Plane() = default;
            ~Plane() override = default;

            // Override the function to test for intersections.
            virtual bool TestIntersection(const RayTracer::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal,
                                        qbVector<double> &localColor) override;

    };
} // namespace RayTracer

