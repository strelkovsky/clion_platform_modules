#pragma once

#include "core/base/window_events.hpp"

namespace backends::glfw
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        auto update() -> void override;
    };
}
