#pragma once

#include <memory>

#include "core/base/window.hpp"
#include "core/base/window_events.hpp"

namespace core::base
{
    class WindowFactory
    {
    public:
        virtual auto create_window() -> std::unique_ptr<Window> = 0;
        virtual auto create_window_events() -> std::unique_ptr<WindowEvents> = 0;

        virtual ~WindowFactory() = default;
    };
}

