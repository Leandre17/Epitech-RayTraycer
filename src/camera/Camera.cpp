/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** camera
*/

#include "Camera.hpp"
#include <math.h>
#include "Ray.hpp"

RayTracer::Camera::Camera() {
    // The default constructor.
    position = Vector3D{std::vector<double>{0.0, -10.0, 0.0}};
    lookAt = Vector3D{std::vector<double>{0.0, 0.0, 0.0}};
    upCorner = Vector3D{std::vector<double>{0.0, 0.0, 1.0}};
    length = 1.0;
    horzSize = 1.0;
    aspectRatio = 1.0;
}

void RayTracer::Camera::SetPosition(const Vector3D &newPosition) { position = newPosition; }

void RayTracer::Camera::SetLookAt(const Vector3D &newLookAt) { lookAt = newLookAt; }

void RayTracer::Camera::SetUp(const Vector3D &upVector) { upCorner = upVector; }

void RayTracer::Camera::SetLength(double newLength) { length = newLength; }

void RayTracer::Camera::SetHorzSize(double newHorzSize) { horzSize = newHorzSize; }

void RayTracer::Camera::SetAspect(double newAspect) { aspectRatio = newAspect; }

// Method to return the position of the camera.
Vector3D RayTracer::Camera::GetPosition() { return position; }

// Method to return the LookAt of the camera.
Vector3D RayTracer::Camera::GetLookAt() { return lookAt; }

// Method to return the up vector of the camera.
Vector3D RayTracer::Camera::GetUp() { return upCorner; }

// Method to return the length of the camera.
double RayTracer::Camera::GetLength() { return length; }

// Method to return the horizontal size.
double RayTracer::Camera::GetHorzSize() { return horzSize; }

// Method to return the camera aspect ratio.
double RayTracer::Camera::GetAspect() { return aspectRatio; }

// Method to return the U vector.
Vector3D RayTracer::Camera::GetU() { return m_projectionScreenU; }

// Method to return the V vector.
Vector3D RayTracer::Camera::GetV() { return m_projectionScreenV; }

// Method to return the projection screen centre.
Vector3D RayTracer::Camera::GetScreenCentre() { return m_projectionScreenCentre; }

// Function to compute camera geometry.
void RayTracer::Camera::UpdateCameraGeometry() {
    // First, compute the vector from the camera position to the LookAt position.
    m_alignmentVector = lookAt - position;
    m_alignmentVector.Normalize();

    // Second, compute the U and V vectors.
    m_projectionScreenU = Vector3D::cross(m_alignmentVector, upCorner);
    m_projectionScreenU.Normalize();
    m_projectionScreenV = Vector3D::cross(m_projectionScreenU, m_alignmentVector);
    m_projectionScreenV.Normalize();

    // Thirdly, compute the positon of the centre point of the screen.
    m_projectionScreenCentre = position + (length * m_alignmentVector);

    // Modify the U and V vectors to match the size and aspect ratio.
    m_projectionScreenU = m_projectionScreenU * horzSize;
    m_projectionScreenV = m_projectionScreenV * (horzSize / aspectRatio);
}

bool RayTracer::Camera::GenerateRay(float proScreenX, float proScreenY, RayTracer::Ray &cameraRay) {
    // Compute the location of the screen point in world coordinates.
    Vector3D screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
    Vector3D screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);

    // Use this point along with the camera position to compute the ray.
    cameraRay.point1 = position;
    cameraRay.point2 = screenWorldCoordinate;
    cameraRay.distance = screenWorldCoordinate - position;

    return true;
}
