/* ***********************************************************
    AObject.cpp

    The AObject class implementation - A base class from which
    all other object classes will inherit.

    This file forms part of the qbRayTrace project as described
    in the series of videos on the QuantitativeBytes YouTube
    channel.

    This code corresponds specifically to Episode 2 of the series,
    which may be found here:
    https://youtu.be/8fWZM8hCX5E

    The whole series may be found on the QuantitativeBytes
    YouTube channel at:
    www.youtube.com/c/QuantitativeBytes

    GPLv3 LICENSE
    Copyright (c) 2021 Michael Bennett

***********************************************************/

// AObject.cpp

#include <math.h>
#include "IObject.hpp"

#define EPSILON 1e-21f;

// Function to test for intersections.
bool RayTracer::AObject::TestIntersection(const Ray &, qbVector<double> &, qbVector<double> &, qbVector<double> &) {
    return false;
}

void RayTracer::AObject::SetTransformMatrix(const RayTracer::GTform &transformMatrix) {
    m_transformMatrix = transformMatrix;
}

// Function to test whether two floating-point numbers are close to being equal.
bool RayTracer::AObject::CloseEnough(const double f1, const double f2) { return fabs(f1 - f2) < EPSILON; }
