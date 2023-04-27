/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** parsing_obj
*/

#include "../../include/parsing/parsing_obj.hpp"

RayTracer::Parsing_OBJ::Parsing_OBJ(char *filepath)
{
    m_filename = filepath;

    try {
        m_cfg.readFile(filepath);
    } catch(const libconfig::FileIOException& e) {
        std::cerr << "Erreur lors de la lecture du fichier : " << e.what() << std::endl;
        exit(84);
    } catch(const libconfig::ParseException& e) {
        std::cerr << "Erreur de syntaxe dans le fichier : " << e.getError() << " à la ligne " << e.getLine() << std::endl;
        exit(84);
    }
    manage_parsing();
}

int RayTracer::Parsing_OBJ::parse_camera()
{
    try {
        const libconfig::Setting& camera = m_cfg.lookup("camera");
        int width = camera["resolution"]["width"];
        int height = camera["resolution"]["height"];
        int x = camera["position"]["x"];
        int y = camera["position"]["y"];
        int z = camera["position"]["z"];
        int rotX = camera["rotation"]["x"];
        int rotY = camera["rotation"]["y"];
        int rotZ = camera["rotation"]["z"];
        double fov = camera["fieldOfView"];
        m_camera_width = width;
        m_camera_height = height;
        m_camera_pos_x = x;
        m_camera_pos_y = y;
        m_camera_pos_z = z;
        m_camera_rotX = rotX;
        m_camera_rotY = rotY;
        m_camera_rotZ = rotZ;
        m_camera_fov = fov;
    }
    catch(const libconfig::SettingNotFoundException& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        exit(84);
    }
}

int RayTracer::Parsing_OBJ::parse_primitives()
{
    try {
        const libconfig::Setting& primitives = m_cfg.lookup("primitives");
        const libconfig::Setting& spheres = primitives["spheres"];
        const libconfig::Setting& planes = primitives["planes"];
        int nbSpheres = spheres.getLength();
        int nbPlanes = planes.getLength();
        m_primitives_nbSpheres = nbSpheres;
        m_primitives_nbPlanes = nbPlanes;
        for(int i = 0; i < nbSpheres; ++i)
        {
            const libconfig::Setting& sphere = spheres[i];
            int x, y, z, r;
            const libconfig::Setting& color = sphere["color"];
            int red, green, blue;
            sphere.lookupValue("x", x);
            sphere.lookupValue("y", y);
            sphere.lookupValue("z", z);
            sphere.lookupValue("r", r);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_spheres.push_back({x, y, z, r, red, green, blue});
        }
        for(int i = 0; i < nbPlanes; ++i)
        {
            const libconfig::Setting& plane = planes[i];
            int axis;
            int position;
            const libconfig::Setting& color = plane["color"];
            int red, green, blue;
            plane.lookupValue("axis", axis);
            plane.lookupValue("position", position);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_planes.push_back({axis, position, red, green, blue});
        }
    }
    catch(const libconfig::SettingNotFoundException& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        exit(84);
    }
}

int RayTracer::Parsing_OBJ::parse_lights()
{
    try {
        const libconfig::Setting& lights = m_cfg.lookup("lights");
        float ambient = lights.lookup("ambient");
        float diffuse = lights.lookup("diffuse");
        m_lights_ambient = ambient;
        m_lights_diffuse = diffuse;
        const libconfig::Setting& point_lights = lights.lookup("point");
        int num_point_lights = point_lights.getLength();
        m_lights_nb_points = num_point_lights;
        for (int i = 0; i < num_point_lights; ++i) {
            const libconfig::Setting& point_light = point_lights[i];
            int x = point_light.lookup("x");
            int y = point_light.lookup("y");
            int z = point_light.lookup("z");
            m_lights_tab_points.push_back({x, y, z});
        }
        const libconfig::Setting& directional_lights = lights.lookup("directional");
        int num_directional_lights = directional_lights.getLength();
        m_lights_nb_directional = num_directional_lights;
        for (int i = 0; i < num_directional_lights; ++i) {
            const libconfig::Setting& directional_light = directional_lights[i];
            int x = directional_light.lookup("x");
            int y = directional_light.lookup("y");
            int z = directional_light.lookup("z");
            m_lights_tab_directional.push_back({x, y, z});
        }
    }
    catch(const libconfig::SettingNotFoundException& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        exit(84);
    }
}

int RayTracer::Parsing_OBJ::manage_parsing()
{
    parse_camera();
    parse_primitives();
    parse_lights();
}