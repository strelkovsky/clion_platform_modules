#pragma once

#include "core/base/window.hpp"
#include "core/window/callbacks.hpp"

namespace core::base
{
    class WindowEvents
    {
    public:
        virtual auto init(Window* window) -> void = 0;
        virtual auto release(Window* window) -> void = 0;

        virtual auto update() -> void = 0;

        virtual ~WindowEvents() = default;

        window::callbacks callbacks;
    };
}