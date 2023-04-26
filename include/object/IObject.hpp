/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** IObject
*/

#pragma once

#include "Algo.hpp"
#include "Ray.hpp"
#include "gtfm.hpp"

namespace RayTracer {
    class IObject {
        public:
            virtual ~IObject() = default;
            virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal,
                                        qbVector<double> &localColor) = 0;
            virtual void SetTransformMatrix(const GTform &transformMatrix) = 0;
            // Function to test whether two floating-point numbers are close to being equal.
            virtual bool CloseEnough(const double f1, const double f2) = 0;

            // The base colour of the object.
            qbVector<double> m_baseColor{3};
            // The geometric transform applied to the object.
            RayTracer::GTform m_transformMatrix;
    };


    class AObject : public IObject {
        public:
            AObject() = default;
            virtual ~AObject() = default;
            virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor);
            void SetTransformMatrix(const GTform &transformMatrix);
            bool CloseEnough(const double f1, const double f2);
    };
} // namespace RayTracer

