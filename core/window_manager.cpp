#include <glfw/glfw3.h>

#include "window_manager.hpp"

namespace core
{
    auto WindowManager::init(const std::unique_ptr<base::WindowFactory>& factory, const window::configuration& configuration) -> void
    {
        _window = factory->create_window();
        _window->create(configuration);

        _window_events = factory->create_window_events();
        _window_events->init(_window.get());
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

    auto WindowManager::window_events() const -> base::WindowEvents *
    {
        return _window_events.get();
    }
}

