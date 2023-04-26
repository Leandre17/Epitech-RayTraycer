/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** gtfm
*/

#include "gtfm.hpp"

RayTracer::GTform::GTform() {
    // Set forward and backward transforms to identity matrices.
    forward.SetToIdentity();
    backward.SetToIdentity();
}

// Construct from a pair of matrices.
RayTracer::GTform::GTform(const Matrix &fwd, const Matrix &bck) {
    // Verify that the inputs are 4x4.
    if ((fwd.GetNumRows() != 4) || (fwd.GetNumCols() != 4) || (bck.GetNumRows() != 4) || (bck.GetNumCols() != 4)) {
        throw std::invalid_argument("Cannot construct GTform, inputs are not all 4x4.");
    }

    forward = fwd;
    backward = bck;
}

// Function to set the transform.
void RayTracer::GTform::SetTransform(const Vector3D &translation, const Vector3D &rotation, const Vector3D &scale) {
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
Matrix RayTracer::GTform::GetForward() { return forward; }
Matrix RayTracer::GTform::GetBackward() { return backward; }

// Function to apply the transform.
RayTracer::Ray RayTracer::GTform::Apply(const RayTracer::Ray &inputRay, bool dirFlag) {
    // Create an output object.
    RayTracer::Ray outputRay;

    if (dirFlag) {
        // Apply the forward transform.
        outputRay.m_point1 = this->Apply(inputRay.m_point1, RayTracer::FORWARD);
        outputRay.m_point2 = this->Apply(inputRay.m_point2, RayTracer::FORWARD);
        outputRay.m_lab = outputRay.m_point2 - outputRay.m_point1;
    } else {
        // Apply the backward transform.
        outputRay.m_point1 = this->Apply(inputRay.m_point1, RayTracer::BACKWARD);
        outputRay.m_point2 = this->Apply(inputRay.m_point2, RayTracer::BACKWARD);
        outputRay.m_lab = outputRay.m_point2 - outputRay.m_point1;
    }

    return outputRay;
}

Vector3D RayTracer::GTform::Apply(const Vector3D &inputVector, bool dirFlag) {
    // Convert inputVector to a 4-element vector.
    std::vector<double> tempData{inputVector.GetElement(0), inputVector.GetElement(1), inputVector.GetElement(2), 1.0};
    Vector3D tempVector{tempData};

    // Create a vector for the result.
    Vector3D resultVector;

    if (dirFlag) {
        // Apply the forward transform.
        resultVector = forward * tempVector;
    } else {
        // Apply the backward transform.
        resultVector = backward * tempVector;
    }
    // Reform the output as a 3-element vector.
    Vector3D outputVector{
        std::vector<double>{resultVector.GetElement(0), resultVector.GetElement(1), resultVector.GetElement(2)}};

    return outputVector;
}
