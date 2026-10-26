#pragma once

#include <memory>

#include "base/window_factory.hpp"

namespace core
{
    class WindowManager
    {
    public:
        auto init(const std::unique_ptr<base::WindowFactory>& factory) -> void;
        auto release() const -> void;
        auto update() const -> void;

        auto window() const -> base::Window*;

    private:
        std::unique_ptr<base::Window> _window;
        std::unique_ptr<base::WindowEvents> _window_events;
    };
}
