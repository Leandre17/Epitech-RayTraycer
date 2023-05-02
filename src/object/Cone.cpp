/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Cone
*/

#include "Cone.hpp"
#include <cmath>

bool RayTracer::Cone::TestIntersection(const RayTracer::Ray &castRay, Vector3D &intPoint, Vector3D &localNormal,Vector3D &localColor) {
    RayTracer::Ray bckRay = m_transformMatrix.Apply(castRay, RayTracer::BACKWARD);
    Vector3D v = bckRay.distance;
    Vector3D p = bckRay.point1;
    v.Normalize();

    double a = std::pow(v.GetElement(0), 2.0) + std::pow(v.GetElement(1), 2.0) - std::pow(v.GetElement(2), 2.0);
    double b =
        2 * (p.GetElement(0) * v.GetElement(0) + p.GetElement(1) * v.GetElement(1) - p.GetElement(2) * v.GetElement(2));
    double c = std::pow(p.GetElement(0), 2.0) + std::pow(p.GetElement(1), 2.0) - std::pow(p.GetElement(2), 2.0);
    double numSQRT = sqrtf(std::pow(b, 2) - 4 * a * c);
    std::array<Vector3D, 3> poi;
    std::array<double, 3> t;

    bool t1Valid, t2Valid, t3Valid;
    if (numSQRT > 0.0) {
        t[0] = (-b + numSQRT) / (2 * a);
        t[1] = (-b - numSQRT) / (2 * a);
        poi[0] = bckRay.point1 + (v * t[0]);
        poi[1] = bckRay.point1 + (v * t[1]);
        if ((t[0] > 0.0) && (poi[0].GetElement(2) > 0.0) && (poi[0].GetElement(2) < 1.0)) {
            t1Valid = true;
        } else {
            t1Valid = false;
            t[0] = 100e6;
        }
        if ((t[1] > 0.0) && (poi[1].GetElement(2) > 0.0) && (poi[1].GetElement(2) < 1.0)) {
            t2Valid = true;
        } else {
            t2Valid = false;
            t[1] = 100e6;
        }
    } else {
        t1Valid = false;
        t2Valid = false;
        t[0] = 100e6;
        t[1] = 100e6;
    }

    // And test the end cap.
    if (CloseEnough(v.GetElement(2), 0.0)) {
        t3Valid = false;
        t[2] = 100e6;
    } else {
        // Compute values for t.
        t[2] = (bckRay.point1.GetElement(2) - 1.0) / -v.GetElement(2);
        // Compute points of intersection.
        poi[2] = bckRay.point1 + t[2] * v;

        // Check if these are valid.
        if ((t[2] > 0.0) &&
            (sqrtf(std::pow(poi[2].GetElement(0), 2.0) + std::pow(poi[2].GetElement(1), 2.0)) < 1.0)) {
            t3Valid = true;
        } else {
            t3Valid = false;
            t[2] = 100e6;
        }
    }

    // If no valid intersections found, then we can stop.
    if ((!t1Valid) && (!t2Valid) && (!t3Valid)) return false;

    // Check for the smallest valid value of t.
    int minIndex = 0;
    double minValue = 10e6;
    for (int i = 0; i < 3; ++i) {
        if (t.at(i) < minValue) {
            minValue = t.at(i);
            minIndex = i;
        }
    }

    /* If minIndex is either 0 or 1, then we have a valid intersection
        with the cone itself. */
    Vector3D validPOI = poi.at(minIndex);
    if (minIndex < 2) {
        // Transform the intersection point back into world coordinates.
        intPoint = m_transformMatrix.Apply(validPOI, RayTracer::FORWARD);

        // Compute the local normal.
        Vector3D orgNormal{3};
        Vector3D newNormal{3};
        Vector3D localOrigin{std::vector<double>{0.0, 0.0, 0.0}};
        Vector3D globalOrigin = m_transformMatrix.Apply(localOrigin, RayTracer::FORWARD);
        double tX = validPOI.GetElement(0);
        double tY = validPOI.GetElement(1);
        double tZ = -sqrtf(pow(tX, 2.0) + pow(tY, 2.0));
        orgNormal.SetElement(0, tX);
        orgNormal.SetElement(1, tY);
        orgNormal.SetElement(2, tZ);
        newNormal = m_transformMatrix.Apply(orgNormal, RayTracer::FORWARD) - globalOrigin;
        newNormal.Normalize();
        localNormal = newNormal;
        localColor = m_baseColor;
        return true;
    } else {
        // Check the end cap.
        if (!CloseEnough(v.GetElement(2), 0.0)) {
            // Check if we are inside the disk.
            if (sqrtf(std::pow(validPOI.GetElement(0), 2.0) + std::pow(validPOI.GetElement(1), 2.0)) < 1.0) {
                // Transform the intersection point back into world coordinates.
                intPoint = m_transformMatrix.Apply(validPOI, RayTracer::FORWARD);
                // Compute the local normal.
                Vector3D localOrigin{std::vector<double>{0.0, 0.0, 0.0}};
                Vector3D normalVector{std::vector<double>{0.0, 0.0, 1.0}};
                Vector3D globalOrigin = m_transformMatrix.Apply(localOrigin, RayTracer::FORWARD);
                localNormal = m_transformMatrix.Apply(normalVector, RayTracer::FORWARD) - globalOrigin;
                localNormal.Normalize();
                localColor = m_baseColor;
                return true;
            } else
                return false;
        } else
            return false;
    }
    return false;
}
