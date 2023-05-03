/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** pointlight
*/

#include "PointLight.hpp"

RayTracer::PointLight::PointLight() {
    m_color = Vector3D{std::vector<double>{1.0, 1.0, 1.0}};
    m_intensity = 1;
}

// Function to compute illumination.
bool RayTracer::PointLight::ComputeIllumination(const Vector3D &intPoint, const Vector3D &localNormal,
                                                const std::vector<std::unique_ptr<RayTracer::IObject>> &objectList,
                                                const std::unique_ptr<RayTracer::IObject> &currentObject,
                                                Vector3D &color, double &intensity)
{
    Vector3D poi{3};
    Vector3D poiNormal{3};
    Vector3D poiColor{3};
    bool validInt = false;
    // Construct a vector pointing from the intersection point to the light.
    Vector3D lightDir = (m_location - intPoint).Normalized();
    Vector3D startPoint = intPoint;
    // Construct a ray from the point of intersection to the light.
    RayTracer::Ray lightRay(startPoint, startPoint + lightDir);

    for (std::size_t i = 0; i < objectList.size(); i++) {
        if (objectList[i] != currentObject)
            validInt = objectList[i]->TestIntersection(lightRay, poi, poiNormal, poiColor);
        if (validInt) break;
    }
    if (!validInt) {
        // Compute the angle between the local normal and the light ray.
        // Note that we assume that localNormal is a unit vector.
        double angle = acos(Vector3D::dot(localNormal, lightDir));

        // If the normal is pointing away from the light, then we have no illumination.
        if (angle > 1.5708) {
            // No illumination.
            color = m_color;
            intensity = 1.0;
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
