/* ***********************************************************
    Ray.hpp

    The ray class implementation - A class to handle rays that can
    be cast around the scene.

    This file forms part of the qbRayTrace project as described
    in the series of videos on the QuantitativeBytes YouTube
    channel.

    This code corresponds specifically to Episode 2 of the series,
    which may be found here:
    https://youtu.be/KBK6g6RFgdA

    The whole series may be found on the QuantitativeBytes
    YouTube channel at:
    www.youtube.com/c/QuantitativeBytes

    GPLv3 LICENSE
    Copyright (c) 2021 Michael Bennett

***********************************************************/

// ray.cpp

#include "Ray.hpp"

RayTracer::Ray::Ray() {
    m_point1 = Vector3D{std::vector<double>{0.0, 0.0, 0.0}};
    m_point2 = Vector3D{std::vector<double>{0.0, 0.0, 1.0}};
    m_lab = m_point2 - m_point1;
}

RayTracer::Ray::Ray(const Vector3D &point1, const Vector3D &point2) {
    m_point1 = point1;
    m_point2 = point2;
    m_lab = m_point2 - m_point1;
}

Vector3D RayTracer::Ray::GetPoint1() const { return m_point1; }

Vector3D RayTracer::Ray::GetPoint2() const { return m_point2; }
