#pragma once

#include <GLFW/glfw3.h>

#include "core/base/window.hpp"

namespace backends::glfw
{
    class Window final : public core::base::Window
    {
    public:
        auto create(const core::window::configuration& configuration) -> void override;
        auto destroy() -> void override;

        auto handle() -> std::any override;

    private:
        GLFWwindow* _handle{};
    };
}
