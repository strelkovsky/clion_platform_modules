#include "window.hpp"

namespace backends::glfw
{
    auto Window::create(std::string_view title, int32_t width, int32_t height) -> void
    {
        glfwInit();

        _handle = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

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

    auto Window::update() -> void
    {
        glfwSwapBuffers(_handle);
        glfwPollEvents();
    }

    auto Window::handle() -> std::any
    {
        return _handle;
    }
}
