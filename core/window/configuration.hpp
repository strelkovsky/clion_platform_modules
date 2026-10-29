#pragma once

#include <string_view>

namespace core::window
{
    struct configuration
    {
        std::string_view name;

        int32_t width;
        int32_t height;

        int32_t samples;
    };
}