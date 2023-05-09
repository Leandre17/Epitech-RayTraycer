/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Builder
*/

#include "Builder.hpp"

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

void RayTracer::Builder::IceCreamBuilder::BuildIceCream()
{
    BuildSphere();
    BuildSphere();
    BuildCone();
    render();
}