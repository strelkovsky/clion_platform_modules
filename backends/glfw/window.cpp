#include "window.hpp"

namespace backends::glfw
{
    auto Window::create(const core::window::configuration& configuration) -> void
    {
        glfwInit();
        glfwWindowHint(GLFW_SAMPLES, configuration.samples);

        _handle = glfwCreateWindow(configuration.width, configuration.height, configuration.name.data(), nullptr, nullptr);

        glfwMakeContextCurrent(_handle);
    }

    auto Window::destroy() -> void
    {
        glfwDestroyWindow(_handle);

        glfwTerminate();
    }

    auto Window::handle() -> std::any
    {
        return _handle;
    }
}
