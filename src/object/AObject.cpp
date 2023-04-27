/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AObject
*/

#include <math.h>
#include "IObject.hpp"

#define EPSILON 1e-21f;

// Function to test for intersections.
bool RayTracer::AObject::TestIntersection(const Ray &, Vector3D &, Vector3D &, Vector3D &) {
    return false;
}

void RayTracer::AObject::SetTransformMatrix(const RayTracer::GTform &transformMatrix) {
    m_transformMatrix = transformMatrix;
}

// Function to test whether two floating-point numbers are close to being equal.
bool RayTracer::AObject::CloseEnough(const double f1, const double f2) { return fabs(f1 - f2) < EPSILON; }
