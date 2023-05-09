/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Builder
*/

#include "Builder.hpp"
#include "Image.hpp"
#include "Camera.hpp"

RayTracer::Builder::IceCreamBuilder::IceCreamBuilder()
{
}

RayTracer::Builder::IceCreamBuilder::~IceCreamBuilder()
{
}

RayTracer::Builder::IceCreamBuilder::IceCreamBuilder(const RayTracer::Builder::IceCreamBuilder &iceCreamBuilder) :
    m_objects(std::move(iceCreamBuilder.m_objects))
{
}

RayTracer::Builder::IceCreamBuilder::IceCreamBuilder(RayTracer::Builder::IceCreamBuilder &&iceCreamBuilder)
    : m_objects(std::move(iceCreamBuilder.m_objects))
{
}

RayTracer::Builder::IceCreamBuilder &RayTracer::Builder::IceCreamBuilder::operator=(const RayTracer::Builder::IceCreamBuilder &iceCreamBuilder)
{
    if (this != &iceCreamBuilder)
        m_objects = std::move(iceCreamBuilder.m_objects);
    return *this;
}

RayTracer::Builder::IceCreamBuilder &RayTracer::Builder::IceCreamBuilder::operator=(RayTracer::Builder::IceCreamBuilder &&iceCreamBuilder)
{
    if (this != &iceCreamBuilder)
        m_objects = std::move(iceCreamBuilder.m_objects);
    return *this;
}

void RayTracer::Builder::IceCreamBuilder::BuildCone()
{
}

void RayTracer::Builder::IceCreamBuilder::BuildSphere()
{
}

void RayTracer::Builder::IceCreamBuilder::render()
{
}

int &RayTracer::Builder::IceCreamBuilder::getObjects()
{
    return this->m_objects;
}

void RayTracer::Builder::IceCreamBuilder::BuildIceCream(RayTracer::Scene &scene)
{
    BuildSphere();
    BuildSphere();
    BuildCone();
    render();

    int number_sphere_existing = scene.m_objectList.size();

    scene.m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::SPHERE)));
    // scene.m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::SPHERE)));
    scene.m_objectList.at(number_sphere_existing - 1)->m_baseColor = Vector3D{std::vector<double>{0.4, 0.3, 0.7}};
    // scene.m_objectList.at(number_sphere_existing)->m_baseColor = Vector3D{std::vector<double>{0.5, 0.2, 0.9}};

    RayTracer::Transform planeMatrix;
    planeMatrix.SetTransform(
            Vector3D{std::vector<double>{0.0, 0.0,
                                         0.0}},
            Vector3D{std::vector<double>{0, 0.0, 0.0}},
            Vector3D{std::vector<double>{0.73, 0.5,
                                         0.75}});
    scene.m_objectList.at(number_sphere_existing - 1)->SetTransformMatrix(planeMatrix);

    // // Modify the spheres.
    // RayTracer::Transform sphereMatrix2;
    // sphereMatrix2.SetTransform(
    //         Vector3D{std::vector<double>{0.0, 0.0,
    //                                      0.0}},
    //         Vector3D{std::vector<double>{0, 0.0, 0.0}},
    //         Vector3D{std::vector<double>{0.63, 0.5,
    //                                      0.85}});
    // scene.m_objectList.at(number_sphere_existing)->SetTransformMatrix(sphereMatrix2);
}