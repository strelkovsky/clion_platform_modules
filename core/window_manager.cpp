#include <glfw/glfw3.h>

#include "window_manager.hpp"

namespace core
{
    auto WindowManager::init(const std::unique_ptr<base::WindowFactory>& factory) -> void
    {
        _window = factory->create_window();
        _window->create({.name = "Hello World", .width = 640, .height = 480});

        _window_events = factory->create_window_events();
    }

    auto WindowManager::release() const -> void
    {
        _window->destroy();
    }

    auto WindowManager::update() const -> void
    {
        glfwSwapBuffers(std::any_cast<GLFWwindow*>(_window->handle()));

        _window_events->update();
    }

    auto WindowManager::window() const -> base::Window*
    {
        return _window.get();
    }
}

