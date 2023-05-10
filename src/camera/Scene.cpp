/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** scene
*/

#include "Scene.hpp"
#include "Factory.hpp"
#include "Builder.hpp"
#include "Director.hpp"

RayTracer::Scene::Scene(RayTracer::Parsing_OBJ parsing) {
    // Configure the camera.
    m_camera.SetPosition(
        Vector3D{std::vector<double>{parsing.m_camera_pos_x, parsing.m_camera_pos_y, parsing.m_camera_pos_z}});
    m_camera.SetLookAt(Vector3D{std::vector<double>{parsing.m_camera_rotX, parsing.m_camera_rotY, parsing.m_camera_rotZ}});
    m_camera.SetUp(Vector3D{std::vector<double>{0.0, 0.0, 1.0}});
    m_camera.SetHorzSize(0.25);
    m_camera.SetAspect(16.0 / 9.0);
    m_camera.UpdateCameraGeometry();

    // Construct all spheres
    int number_spheres = parsing.m_primitives_nbSpheres;
    for (int i = 0; i < number_spheres; i++) {
        m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::SPHERE)));
        m_objectList.at(i)->m_baseColor =
            Vector3D{std::vector<double>{parsing.m_primitives_tab_spheres[i][4], parsing.m_primitives_tab_spheres[i][5],
                                         parsing.m_primitives_tab_spheres[i][6]}};
    }

    // Construct all planes
    int number_planes = parsing.m_primitives_nbPlanes;
    for (int i = 0; i < number_planes; i++) {
        m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::PLANE)));
        m_objectList.at(number_spheres + i)->m_baseColor =
            Vector3D{std::vector<double>{parsing.m_primitives_tab_planes[i][2], parsing.m_primitives_tab_planes[i][3],
                                         parsing.m_primitives_tab_planes[i][4]}};
    }

    // Define a transform for the plane.
    RayTracer::Transform planeMatrix;
    planeMatrix.SetTransform(Vector3D{std::vector<double>{0.0, 0.0, 0.75}}, Vector3D{std::vector<double>{0.0, 0.0, 0.0}},
                             Vector3D{std::vector<double>{4.0, 4.0, 1.0}});
    m_objectList.at(number_spheres)->SetTransformMatrix(planeMatrix);

    // Modify the spheres.
    for (int i = 0; i < number_spheres; i++) {
        RayTracer::Transform sphereMatrix;
        sphereMatrix.SetTransform(
            Vector3D{std::vector<double>{parsing.m_primitives_tab_spheres[i][0], parsing.m_primitives_tab_spheres[i][1],
                                         parsing.m_primitives_tab_spheres[i][2]}},
            Vector3D{std::vector<double>{parsing.m_primitives_tab_spheres[i][3], 0.0, 0.0}},
            Vector3D{std::vector<double>{parsing.m_primitives_tab_spheres[i][7], parsing.m_primitives_tab_spheres[i][8],
                                         parsing.m_primitives_tab_spheres[i][9]}});
        m_objectList.at(i)->SetTransformMatrix(sphereMatrix);
    }

    // construct and modify cones / cylindres
    int number_cones = parsing.m_primitives_nbCones;
    int number_cylindres = parsing.m_primitives_nbCylindre;
    for (int i = 0; i < number_cones; i++) {
        m_objectList.push_back(std::move(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::CONE)));
        m_objectList.at(number_planes + number_spheres + i);
        RayTracer::Transform sphereMatrix;
        sphereMatrix.SetTransform(Vector3D{std::vector<double>{parsing.m_primitives_tab_cones[i][0], parsing.m_primitives_tab_cones[i][1], parsing.m_primitives_tab_cones[i][2]}},
            Vector3D{std::vector<double>{0.0, 0.0, 0.0}},
            Vector3D{std::vector<double>{1.0, 1.0, 1.0}});
        m_objectList.at(number_planes + number_spheres)->SetTransformMatrix(sphereMatrix);
        m_objectList.at(number_planes + number_spheres)->m_baseColor = Vector3D{std::vector<double>{parsing.m_primitives_tab_cones[i][3], parsing.m_primitives_tab_cones[i][4], parsing.m_primitives_tab_cones[i][5]}};
    }

    for (int i = 0; i < number_cylindres; i++) {
        m_objectList.push_back(RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE::CYLINDRE));
        m_objectList.at(number_planes + number_spheres + 1);
        RayTracer::Transform cylindreMatrix;
        cylindreMatrix.SetTransform(Vector3D{std::vector<double>{parsing.m_primitives_tab_cylindres[i][0], parsing.m_primitives_tab_cylindres[i][1], parsing.m_primitives_tab_cylindres[i][2]}},
            Vector3D{std::vector<double>{0.0, 0.0, 0.0}},
            Vector3D{std::vector<double>{.5, .5, .5}});
        m_objectList.at(number_planes + number_spheres + 1)->SetTransformMatrix(cylindreMatrix);
        m_objectList.at(number_planes + number_spheres + 1)->m_baseColor = Vector3D{std::vector<double>{parsing.m_primitives_tab_cylindres[i][3], parsing.m_primitives_tab_cylindres[i][4], parsing.m_primitives_tab_cylindres[i][5]}};
    }

    // Design patern BUILDER
    RayTracer::Builder::IceCreamBuilder iceCream;
    RayTracer::Director director(iceCream);
    director.createIceCream(*this, parsing);

    // Construct a test light.
    // m_lightList.push_back(std::make_unique<RayTracer::PointLight>(RayTracer::PointLight()));
    // m_lightList.at(0)->m_location = Vector3D{std::vector<double>{5.0, -10.0, -5.0}};
    // m_lightList.at(0)->m_color = Vector3D{std::vector<double>{0.0, 0.0, 1.0}};

    m_lightList.push_back(RayTracer::Factory::CreateLight(RayTracer::LIGHTTYPE::POINT));
    m_lightList.at(0)->m_location = Vector3D{std::vector<double>{0, -10.0, -5.0}};
    m_lightList.at(0)->m_color = Vector3D{std::vector<double>{1.0, 1.0, 1.0}};

    // m_lightList.push_back(std::make_unique<RayTracer::PointLight>(RayTracer::PointLight()));
    // m_lightList.at(2)->m_location = Vector3D{std::vector<double>{0.0, -10.0, -5.0}};
    // m_lightList.at(2)->m_color = Vector3D{std::vector<double>{0.0, 1.0, 0.0}};
}

bool RayTracer::Scene::Render(RayTracer::Image &outputImage) {
    int xSize = outputImage.GetWidth();
    int ySize = outputImage.GetHeight();

    RayTracer::Ray cameraRay;
    Vector3D intPoint(3);
    Vector3D localNormal(3);
    Vector3D localColor(3);
    double xFact = 1.0 / (xSize / 2.0);
    double yFact = 1.0 / (ySize / 2.0);

    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {
            double normX = x * xFact - 1.0;
            double normY = y * yFact - 1.0;
            m_camera.GenerateRay(normX, normY, cameraRay);

            // Test for intersections with all objects in the scene.
            std::unique_ptr<RayTracer::IObject> closestObject = std::make_unique<RayTracer::AObject>();
            Vector3D closestIntPoint{3};
            Vector3D closestLocalNormal{3};
            Vector3D closestLocalColor{3};
            double minDist = 1e6;
            bool intersectionFound = false;
            for (std::size_t i = 0; i < m_objectList.size(); i++) {
                bool validInt = m_objectList[i]->TestIntersection(cameraRay, intPoint, localNormal, localColor);

                // If we have a valid intersection.
                if (validInt) {
                    // Set the flag to indicate that we found an intersection.
                    intersectionFound = true;

                    // Compute the distance between the camera and the point of intersection.
                    double dist = (intPoint - cameraRay.point1).norm();

                    if (dist < minDist) {
                        minDist = dist;
                        closestObject->m_baseColor = m_objectList[i]->m_baseColor;
                        closestObject->m_transformMatrix = m_objectList[i]->m_transformMatrix;
                        closestIntPoint = intPoint;
                        closestLocalNormal = localNormal;
                        closestLocalColor = localColor;
                    }
                }
            }
            if (intersectionFound) {
                // Compute the intensity of illumination.
                double intensity = 1;
                Vector3D color{3};
                double red = 0.0;
                double green = 0.0;
                double blue = 0.0;
                bool validIllum = false;
                bool illumFound = false;
                for (std::size_t i = 0; i < m_lightList.size(); i++) {
                    validIllum = m_lightList[i]->ComputeIllumination(closestIntPoint, closestLocalNormal, m_objectList,
                                                                     closestObject, color, intensity);
                    if (validIllum) {
                        illumFound = true;
                        red += color.GetElement(0) * intensity;
                        green += color.GetElement(1) * intensity;
                        blue += color.GetElement(2) * intensity;
                    }
                }

                if (illumFound) {
                    red *= closestLocalColor.GetElement(0);
                    green *= closestLocalColor.GetElement(1);
                    blue *= closestLocalColor.GetElement(2);
                    outputImage.SetPixel(x, y, red * 255, green * 255, blue * 255);
                }
            }
        }
    }
    return true;
}
