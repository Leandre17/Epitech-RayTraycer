/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** objplane
*/

#include "Plane.hpp"
#include <cmath>

bool RayTracer::Plane::TestIntersection(const RayTracer::Ray &castRay, Vector3D &intPoint, Vector3D &localNormal,
                                        Vector3D &localColor) {
    // Copy the ray and apply the backwards transform.
    RayTracer::Ray bckRay = m_transformMatrix.Apply(castRay, RayTracer::BACKWARD);

    // Copy the distance vector from bckRay and normalize it.
    Vector3D k = bckRay.distance;
    k.Normalize();

    /* Check if there is an intersection, ie. */
    if (!CloseEnough(k.GetElement(2), 0.0)) {
        // There is an intersection.
        double t = bckRay.point1.GetElement(2) / -k.GetElement(2);
        if (t > 0.0) {
            double u = bckRay.point1.GetElement(0) + (k.GetElement(0) * t);
            double v = bckRay.point1.GetElement(1) + (k.GetElement(1) * t);

            if ((abs(u) < 1.0) && (abs(v) < 1.0)) {
                // Compute the point of intersection.
                Vector3D poi = bckRay.point1 + t * k;

                // Transform the intersection point back into world coordinates.
                intPoint = m_transformMatrix.Apply(poi, RayTracer::FORWARD);

                // Compute the local normal.
                Vector3D localOrigin{std::vector<double>{0.0, 0.0, 0.0}};
                Vector3D normalVector{std::vector<double>{0.0, 0.0, -1.0}};
                Vector3D globalOrigin = m_transformMatrix.Apply(localOrigin, RayTracer::FORWARD);
                localNormal = m_transformMatrix.Apply(normalVector, RayTracer::FORWARD) - globalOrigin;
                localNormal.Normalize();

                // Return the base color.
                localColor = m_baseColor;
                return true;
            } else
                return false;
        } else
            return false;
    }
    return false;
}
