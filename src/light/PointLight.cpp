/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** pointlight
*/

#include "PointLight.hpp"

RayTracer::PointLight::PointLight() {
    m_color = Vector3D{std::vector<double>{1.0, 1.0, 1.0}};
    m_intensity = 1.0;
}

// Function to compute illumination.
bool RayTracer::PointLight::ComputeIllumination(const Vector3D &intPoint, const Vector3D &localNormal,
                                                const std::vector<std::unique_ptr<RayTracer::AObject>> &objectList,
                                                const std::unique_ptr<RayTracer::AObject> &currentObject,
                                                Vector3D &color, double &intensity) {
    // Construct a vector pointing from the intersection point to the light.
    Vector3D lightDir = (m_location - intPoint).Normalized();

    // Compute a starting point.
    Vector3D startPoint = intPoint;

    // Construct a ray from the point of intersection to the light.
    RayTracer::Ray lightRay(startPoint, startPoint + lightDir);

    /* Check for intersections with all of the objects
        in the scene, except for the current one. */
    Vector3D poi{3};
    Vector3D poiNormal{3};
    Vector3D poiColor{3};
    bool validInt = false;
    for (std::size_t i = 0; i < objectList.size(); i++) {
        if (objectList[i] != currentObject) {
            validInt = objectList[i]->TestIntersection(lightRay, poi, poiNormal, poiColor);
        }

        /* If we have an intersection, then there is no point checking further
            so we can break out of the loop. In other words, this object is
            blocking light from this light source. */
        if (validInt) break;
    }

    /* Only continue to compute illumination if the light ray didn't
        intersect with any objects in the scene. Ie. no objects are
        casting a shadow from this light source. */
    if (!validInt) {
        // Compute the angle between the local normal and the light ray.
        // Note that we assume that localNormal is a unit vector.
        double angle = acos(Vector3D::dot(localNormal, lightDir));

        // If the normal is pointing away from the light, then we have no illumination.
        if (angle > 1.5708) {
            // No illumination.
            color = m_color;
            intensity = 0.0;
            return false;
        } else {
            // We do have illumination.
            color = m_color;
            intensity = m_intensity * (1.0 - (angle / 1.5708));
            return true;
        }
    } else {
        // Shadow, so no illumination.
        color = m_color;
        intensity = 0.0;
        return false;
    }
}
