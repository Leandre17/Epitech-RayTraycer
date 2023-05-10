/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Director
*/

#include "Director.hpp"

RayTracer::Director::Director(RayTracer::Builder::IceCreamBuilder builder) :
    m_builder(builder)
{
}

RayTracer::Director::~Director()
{
}

RayTracer::Director::Director(const RayTracer::Director &other) :
    m_builder(other.m_builder)
{
}

RayTracer::Director::Director(RayTracer::Director &&other) :
    m_builder(std::move(other.m_builder))
{
}

RayTracer::Director &RayTracer::Director::operator=(const RayTracer::Director &other)
{
    this->m_builder = other.m_builder;
    return *this;
}

RayTracer::Director &RayTracer::Director::operator=(RayTracer::Director &&other)
{
    this->m_builder = std::move(other.m_builder);
    return *this;
}

void RayTracer::Director::createIceCream(RayTracer::Scene &scene, RayTracer::Parsing_OBJ &parsing)
{
    m_builder.BuildIceCream(scene, parsing);
}
