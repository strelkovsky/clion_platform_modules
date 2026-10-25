#pragma once

#include <memory>

#include "core/base/window.hpp"

namespace core::base
{
    class WindowFactory
    {
    public:
        virtual auto create_window() -> std::unique_ptr<Window> = 0;

        virtual ~WindowFactory() = default;
    };
}

