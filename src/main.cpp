
#include "Image.hpp"
#include "Scene.hpp"
#include <filesystem>

std::string getfilename(std::string filename) {
    std::string filepath = ((std::filesystem::path)filename).stem();

    filepath = "./screenshots/" + filepath + ".ppm";
    return filepath;
}

int main(int ac, char**av) {
    RayTracer::Image m_image{1280, 720};
    RayTracer::Scene m_scene;

    m_scene.Render(m_image);
    if (ac == 1)
        m_image.Display();
    else
        m_image.Display(getfilename(av[1]));
}
