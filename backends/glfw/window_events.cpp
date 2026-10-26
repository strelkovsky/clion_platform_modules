#include "window_events.hpp"

#include "GLFW/glfw3.h"

#include <print>

namespace backends::glfw
{
    auto WindowEvents::init(core::base::Window *window) -> void
    {
        const auto handle = std::any_cast<GLFWwindow*>(window->handle());

        glfwSetWindowUserPointer(handle, this);

        glfwSetWindowCloseCallback(handle, [](GLFWwindow* window_handle)
        {
            if (const auto window_events = static_cast<core::base::WindowEvents*>(glfwGetWindowUserPointer(window_handle)); window_events->callbacks.on_close)
            {
                window_events->callbacks.on_close();
            }
        });

        glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* window_handle, int width, int height)
        {
            if (const auto window_events = static_cast<core::base::WindowEvents*>(glfwGetWindowUserPointer(window_handle)); window_events->callbacks.on_resize)
            {
                window_events->callbacks.on_resize(width, height);
            }
        });

        glfwSetErrorCallback([](int error, const char* description)
        {
            std::println("Error: {} {}", error, description);

            // if (const auto window_events = static_cast<core::base::WindowEvents*>(glfwGetWindowUserPointer(handle)); window_events->callbacks.on_error)
            // {
            //     window_events->callbacks.on_error(error, description);
            // }
        });
    }

    auto WindowEvents::release([[maybe_unused]] core::base::Window *window) -> void
    {
    }

    auto WindowEvents::update() -> void
    {
        glfwPollEvents();
    }
}
