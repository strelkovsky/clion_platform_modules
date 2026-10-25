#pragma once

#include <GLFW/glfw3.h>

#include "core/base/window.hpp"

namespace backends::glfw
{
    class Window : public core::base::Window
    {
    public:
        auto create(std::string_view title, int32_t width, int32_t height) -> void override;
        auto destroy() -> void override;
        auto update() -> void override;

        auto handle() -> std::any override;

    private:
        GLFWwindow* _handle{};
    };
}
