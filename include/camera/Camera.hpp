/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** camera
*/

#pragma once

#include "Algo.hpp"
#include "Ray.hpp"

namespace RayTracer {
class Camera {
public:
    Camera();
    void SetPosition(const Vector3D &newPosition);
    void SetLookAt(const Vector3D &newLookAt);
    void SetUp(const Vector3D &upVector);
    void SetLength(double newLength);
    void SetHorzSize(double newSize);
    void SetAspect(double newAspect);
    Vector3D GetPosition();
    Vector3D GetLookAt();
    Vector3D GetUp();
    Vector3D GetU();
    Vector3D GetV();
    Vector3D GetScreenCentre();
    double GetLength();
    double GetHorzSize();
    double GetAspect();

    // Function to generate a ray.
    bool GenerateRay(float proScreenX, float proScreenY, RayTracer::Ray &cameraRay);
    // Function to update the camera geometry.
    void UpdateCameraGeometry();

private:
    Vector3D position{3};
    Vector3D lookAt{3};
    Vector3D upCorner{3};
    double length;
    double horzSize;
    double aspectRatio;

    Vector3D m_alignmentVector{3};
    Vector3D m_projectionScreenU{3};
    Vector3D m_projectionScreenV{3};
    Vector3D m_projectionScreenCentre{3};
};
} // namespace RayTracer
