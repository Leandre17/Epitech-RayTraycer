
#include "Image.hpp"
#include "Scene.hpp"
#include "parsing_obj.hpp"
#include <filesystem>
#include <string>

static std::string getfilename(std::string filename) {
    std::string filepath = ((std::filesystem::path)filename).stem();

    filepath = "./screenshots/" + filepath + ".ppm";
    return filepath;
}

static int show_help(void)
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "  SCENE_FILE: scene configuration" << std::endl;
    return (0);
}

static int launch_raytracer(char *scene_path)
{
    RayTracer::Parsing_OBJ parsing(scene_path);
    RayTracer::Image m_image{parsing.m_camera_width, parsing.m_camera_height};
    RayTracer::Scene m_scene(scene_path);

    m_scene.Render(m_image);
    m_image.Display(getfilename(scene_path));
    return 0;
}

int main(int ac, char**av) {

    if (ac != 2) {
        return (84);
    } else {
        if (av[1] == std::string("--help"))
            return show_help();
        else
            return launch_raytracer(av[1]);
    }
    return (0);
}
