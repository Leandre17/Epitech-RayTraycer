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

void RayTracer::Builder::IceCreamBuilder::BuildIceCream(RayTracer::Scene &scene, RayTracer::Parsing_OBJ &parsing)
{
    BuildSphere();
    BuildSphere();
    BuildCone();
    render();

    // Construct icecream
    int number_all_before = scene.m_objectList.size();
    int number_icecream = parsing.m_primitives_nbIcecream;
    for (int i = 0; i < number_icecream; ++i) {
        // Add sphere 1
        scene.m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::SPHERE)));
        scene.m_objectList.at(number_all_before + i * 2)->m_baseColor =
            Vector3D{std::vector<double>{1, 0.5, 0.5}};

        // Add sphere 2
        scene.m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::SPHERE)));
        scene.m_objectList.at(number_all_before + i * 2 + 1)->m_baseColor =
            Vector3D{std::vector<double>{0.5, 0.5, 1}};

        // Add cone
        scene.m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::CONE)));
        scene.m_objectList.at(number_all_before + i * 2 + 2)->m_baseColor =
            Vector3D{std::vector<double>{0.97, 0.89, 0.71}};
    }

    // Modify the icecream.
    for (int i = 0; i < number_icecream; i++) {
        // Set transformations for sphere 1
        RayTracer::Transform sphere1Matrix;
        sphere1Matrix.SetTransform(
            Vector3D{std::vector<double>{parsing.m_primitives_tab_icecream[i][0] + 0.3, parsing.m_primitives_tab_icecream[i][1], parsing.m_primitives_tab_icecream[i][2] - 1.5}},
            Vector3D{std::vector<double>{0.0, 0.0, 0.0}},
            Vector3D{std::vector<double>{0.5, 0.5,
                                        0.5}});
        scene.m_objectList.at(i * 3 + number_all_before)->SetTransformMatrix(sphere1Matrix);

        // Set transformations for sphere 2
        RayTracer::Transform sphere2Matrix;
        sphere2Matrix.SetTransform(
            Vector3D{std::vector<double>{parsing.m_primitives_tab_icecream[i][0] - 0.2, parsing.m_primitives_tab_icecream[i][1], parsing.m_primitives_tab_icecream[i][2] - 1}},
            Vector3D{std::vector<double>{0.0, 0.0, 0.0}},
            Vector3D{std::vector<double>{0.5, 0.5, 0.5}});
        scene.m_objectList.at(i * 3 + number_all_before + 1)->SetTransformMatrix(sphere2Matrix);

        // Set transformations for cone
        RayTracer::Transform coneMatrix;
        coneMatrix.SetTransform(Vector3D{std::vector<double>{parsing.m_primitives_tab_icecream[i][0], parsing.m_primitives_tab_icecream[i][1], parsing.m_primitives_tab_icecream[i][2]}},
                Vector3D{std::vector<double>{0, 15.5, 0}},
                Vector3D{std::vector<double>{1.0, 1.0, 1.0}});
        scene.m_objectList.at(i * 3 + number_all_before + 2)->SetTransformMatrix(coneMatrix);
    }

}