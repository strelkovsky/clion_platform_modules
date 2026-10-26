#pragma once

#include <any>

#include "core/window/configuration.hpp"

namespace core::base
{
    class Window
    {
    public:
        virtual auto create(const window::configuration& configuration) -> void = 0;
        virtual auto destroy() -> void = 0;

        virtual auto handle() -> std::any = 0;

        virtual ~Window() = default;

        bool is_closing { }; // TODO to be removed - tests
    };
}