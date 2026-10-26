#include "window.hpp"

namespace backends::glfw
{
    auto Window::create(const core::window::configuration& configuration) -> void
    {
        glfwInit();

        _handle = glfwCreateWindow(configuration.width, configuration.height, configuration.name.data(), nullptr, nullptr);

        glfwSetWindowUserPointer(_handle, this);

        glfwSetWindowCloseCallback(_handle, [](GLFWwindow* window_handle)
        {
            const auto window = static_cast<core::base::Window*>(glfwGetWindowUserPointer(window_handle));
            window->is_closing = true;
        });

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
