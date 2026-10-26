#include "window_events.hpp"

#include "GLFW/glfw3.h"

namespace backends::glfw
{
    auto WindowEvents::update() -> void
    {
        glfwPollEvents();
    }
}
