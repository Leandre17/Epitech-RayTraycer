/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AObject
*/

#include <math.h>
#include "IObject.hpp"

bool RayTracer::AObject::TestIntersection(const Ray &, Vector3D &, Vector3D &, Vector3D &) { return false; }

void RayTracer::AObject::SetTransformMatrix(const RayTracer::Transform &transformMatrix) {m_transformMatrix = transformMatrix;}

// Function to test whether two floating-point numbers are close to being equal.
bool RayTracer::AObject::CloseEnough(const double f1, const double f2) { return abs(f1 - f2) < 0.000001; }
