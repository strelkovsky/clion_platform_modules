#pragma once

#include <functional>

namespace core::window
{
    struct callbacks
    {
        [[maybe_unused]] std::function<void(int32_t error_code, std::string_view description)> on_error { };

        [[maybe_unused]] std::function<void(int32_t width, int32_t height)> on_resize { };
        [[maybe_unused]] std::function<void()> on_close { };
    };
}

