#include <glfw/glfw3.h>

#include "window_manager.hpp"

namespace core
{
    auto WindowManager::init(const std::unique_ptr<base::WindowFactory>& factory) -> void
    {
        _window = factory->create_window();
        _window->create({.name = "Hello World", .width = 640, .height = 480});
    }

    auto WindowManager::release() const -> void
    {
        _window->destroy();
    }

    auto WindowManager::update() const -> void
    {
        glfwSwapBuffers(std::any_cast<GLFWwindow*>(_window->handle()));
        glfwPollEvents();
    }

    auto WindowManager::window() const -> base::Window*
    {
        return _window.get();
    }
}

