/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Transform
*/

#include "Transform.hpp"

RayTracer::Transform::Transform() {
    // Set forward and backward transforms to identity matrices.
    forward.SetToIdentity();
    backward.SetToIdentity();
}

// Function to set the transform.
void RayTracer::Transform::SetTransform(const Vector3D &translation, const Vector3D &rotation, const Vector3D &scale) {
    // Define a matrix for each component of the transform.
    Matrix translationMatrix{4, 4};
    Matrix rotationMatrixX{4, 4};
    Matrix rotationMatrixY{4, 4};
    Matrix rotationMatrixZ{4, 4};
    Matrix scaleMatrix{4, 4};

    // Set these to identity.
    translationMatrix.SetToIdentity();
    rotationMatrixX.SetToIdentity();
    rotationMatrixY.SetToIdentity();
    rotationMatrixZ.SetToIdentity();
    scaleMatrix.SetToIdentity();

    // Populate these with the appropriate values.
    // First the translation matrix.
    translationMatrix.SetElement(0, 3, translation.GetElement(0));
    translationMatrix.SetElement(1, 3, translation.GetElement(1));
    translationMatrix.SetElement(2, 3, translation.GetElement(2));

    // Rotation matrices.
    rotationMatrixZ.SetElement(0, 0, cos(rotation.GetElement(2)));
    rotationMatrixZ.SetElement(0, 1, -sin(rotation.GetElement(2)));
    rotationMatrixZ.SetElement(1, 0, sin(rotation.GetElement(2)));
    rotationMatrixZ.SetElement(1, 1, cos(rotation.GetElement(2)));

    rotationMatrixY.SetElement(0, 0, cos(rotation.GetElement(1)));
    rotationMatrixY.SetElement(0, 2, sin(rotation.GetElement(1)));
    rotationMatrixY.SetElement(2, 0, -sin(rotation.GetElement(1)));
    rotationMatrixY.SetElement(2, 2, cos(rotation.GetElement(1)));

    rotationMatrixX.SetElement(1, 1, cos(rotation.GetElement(0)));
    rotationMatrixX.SetElement(1, 2, -sin(rotation.GetElement(0)));
    rotationMatrixX.SetElement(2, 1, sin(rotation.GetElement(0)));
    rotationMatrixX.SetElement(2, 2, cos(rotation.GetElement(0)));

    // And the scale matrix.
    scaleMatrix.SetElement(0, 0, scale.GetElement(0));
    scaleMatrix.SetElement(1, 1, scale.GetElement(1));
    scaleMatrix.SetElement(2, 2, scale.GetElement(2));

    // Combine to give the final forward transform matrix.
    forward = translationMatrix * scaleMatrix * rotationMatrixX * rotationMatrixY * rotationMatrixZ;

    // Compute the backwards transform.
    backward = forward;
    backward.Inverse();
}

// Functions to return the transform matrices.
Matrix RayTracer::Transform::GetForward() { return forward; }
Matrix RayTracer::Transform::GetBackward() { return backward; }

// Function to apply the transform.
RayTracer::Ray RayTracer::Transform::Apply(const RayTracer::Ray &inputRay, bool dirFlag) {
    RayTracer::Ray outputRay;

    if (dirFlag) {
        // Apply the forward transform.
        outputRay.point1 = this->Apply(inputRay.point1, RayTracer::FORWARD);
        outputRay.point2 = this->Apply(inputRay.point2, RayTracer::FORWARD);
        outputRay.distance = outputRay.point2 - outputRay.point1;
    } else {
        // Apply the backward transform.
        outputRay.point1 = this->Apply(inputRay.point1, RayTracer::BACKWARD);
        outputRay.point2 = this->Apply(inputRay.point2, RayTracer::BACKWARD);
        outputRay.distance = outputRay.point2 - outputRay.point1;
    }
    return outputRay;
}

Vector3D RayTracer::Transform::Apply(const Vector3D &inputVector, bool dirFlag) {
    Vector3D resultVector;
    std::vector<double> tempData{inputVector.GetElement(0), inputVector.GetElement(1), inputVector.GetElement(2), 1.0};
    Vector3D tempVector{tempData};

    if (dirFlag)
        resultVector = forward * tempVector;
    else
        resultVector = backward * tempVector;

    // Reform the output as a 3-element vector.
    Vector3D outputVector{
        std::vector<double>{resultVector.GetElement(0), resultVector.GetElement(1), resultVector.GetElement(2)}};

    return outputVector;
}
