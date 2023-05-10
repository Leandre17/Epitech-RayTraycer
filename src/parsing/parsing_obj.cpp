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
    return 0;
}

int RayTracer::Parsing_OBJ::parse_primitives()
{
    try {
        const libconfig::Setting& primitives = m_cfg.lookup("primitives");
        const libconfig::Setting& spheres = primitives["spheres"];
        const libconfig::Setting& planes = primitives["planes"];
        const libconfig::Setting& cones = primitives["cones"];
        const libconfig::Setting& cylindres = primitives["cylindre"];
        int nbSpheres = spheres.getLength();
        int nbPlanes = planes.getLength();
        int nbCones = cones.getLength();
        int nbCylindres = cylindres.getLength();
        m_primitives_nbSpheres = nbSpheres;
        m_primitives_nbPlanes = nbPlanes;
        m_primitives_nbCones = nbCones;
        m_primitives_nbCylindre = nbCylindres;
        for(int i = 0; i < nbSpheres; ++i)
        {
            const libconfig::Setting& sphere = spheres[i];
            double x, y, z, r;
            const libconfig::Setting& color = sphere["color"];
            double red, green, blue;
            double scale_x, scale_y, scale_z;
            sphere.lookupValue("x", x);
            sphere.lookupValue("y", y);
            sphere.lookupValue("z", z);
            sphere.lookupValue("r", r);
            sphere.lookupValue("scale_x", scale_x);
            sphere.lookupValue("scale_y", scale_y);
            sphere.lookupValue("scale_z", scale_z);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_spheres.push_back({x, y, z, r, red, green, blue, scale_x, scale_y, scale_z});
        }
        for(int i = 0; i < nbPlanes; ++i)
        {
            const libconfig::Setting& plane = planes[i];
            double axis;
            double position;
            const libconfig::Setting& color = plane["color"];
            double red, green, blue;
            plane.lookupValue("axis", axis);
            plane.lookupValue("position", position);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_planes.push_back({axis, position, red, green, blue});
        }
        for(int i = 0; i < nbCones; ++i)
        {
            const libconfig::Setting& cone = cones[i];
            const libconfig::Setting& color = cone["color"];
            double red, green, blue;
            double x, y, z;
            cone.lookupValue("x", x);
            cone.lookupValue("y", y);
            cone.lookupValue("z", z);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_cones.push_back({x, y, z, red, green, blue});
        }
        for(int i = 0; i < nbCylindres; ++i)
        {
            const libconfig::Setting& cylindre = cylindres[i];
            const libconfig::Setting& color = cylindre["color"];
            double red, green, blue;
            double x, y, z;
            cylindre.lookupValue("x", x);
            cylindre.lookupValue("y", y);
            cylindre.lookupValue("z", z);
            color.lookupValue("r", red);
            color.lookupValue("g", green);
            color.lookupValue("b", blue);
            m_primitives_tab_cylindres.push_back({x, y, z, red, green, blue});
        }
    }
    catch(const libconfig::SettingNotFoundException& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        exit(84);
    }
    return 0;
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
    return 0;
}

int RayTracer::Parsing_OBJ::print_tab_int(std::vector<std::vector<int>> tab) {
    for (const auto& sub_tab : tab) {
        for (const auto& i : sub_tab) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}

int RayTracer::Parsing_OBJ::print_tab_double(std::vector<std::vector<double>> tab) {
    for (const auto& sub_tab : tab) {
        for (const auto& i : sub_tab) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}

int RayTracer::Parsing_OBJ::parse_icecream()
{
    try {
        const libconfig::Setting& primitives = m_cfg.lookup("primitives");
        const libconfig::Setting& icecream = primitives["icecream"];
        int nbIcecream = icecream.getLength();
        m_primitives_nbIcecream = nbIcecream;
        for(int i = 0; i < nbIcecream; ++i)
        {
            const libconfig::Setting& sphere = icecream[i];
            double x, y, z;
            sphere.lookupValue("x", x);
            sphere.lookupValue("y", y);
            sphere.lookupValue("z", z);
            m_primitives_tab_icecream.push_back({x, y, z});
        }
    }
    catch(const libconfig::SettingNotFoundException& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        exit(84);
    }
    return 0;
}

int RayTracer::Parsing_OBJ::print_informations()
{
    std::cout << "[GENERAL]" << std::endl;
    std::cout << m_filename << std::endl << std::endl;
    std::cout << "[CAMERA]" << std::endl;
    std::cout << m_camera_width << std::endl;
    std::cout << m_camera_height << std::endl;
    std::cout << m_camera_pos_x << std::endl;
    std::cout << m_camera_pos_y << std::endl;
    std::cout << m_camera_pos_z << std::endl;
    std::cout << m_camera_rotX << std::endl;
    std::cout << m_camera_rotY << std::endl;
    std::cout << m_camera_rotZ << std::endl;
    std::cout << m_camera_fov << std::endl << std::endl;
    std::cout << "[PRIMITIVES]" << std::endl;
    std::cout << m_primitives_nbSpheres << std::endl;
    std::cout << m_primitives_nbPlanes << std::endl;
    print_tab_double(m_primitives_tab_spheres);
    print_tab_double(m_primitives_tab_planes);
    std::cout << std::endl;
    std::cout << "[LIGHTS]" << std::endl;
    std::cout << m_lights_ambient << std::endl;
    std::cout << m_lights_diffuse << std::endl;
    std::cout << m_lights_nb_points << std::endl;
    std::cout << m_lights_nb_directional << std::endl;
    print_tab_int(m_lights_tab_points);
    print_tab_int(m_lights_tab_directional);
    std::cout << std::endl;
    return 0;
}

int RayTracer::Parsing_OBJ::manage_parsing()
{
    parse_camera();
    parse_primitives();
    parse_lights();
    parse_icecream();
    // print_informations();
    return 0;
}