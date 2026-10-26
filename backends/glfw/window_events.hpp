#pragma once

#include "core/base/window_events.hpp"

namespace backends::glfw
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto init(core::base::Window *window) -> void override;

        auto release(core::base::Window *window) -> void override;

        auto update() -> void override;
    };
}
