#pragma once

#include <any>
#include <string_view>

namespace core::base
{
    class Window
    {
    public:
        virtual auto create(std::string_view title, int32_t width, int32_t height) -> void = 0;
        virtual auto destroy() -> void = 0;
        virtual auto update() -> void = 0;

        virtual auto handle() -> std::any = 0;

        virtual ~Window() = default;

        bool is_closing { }; // TODO to be removed - tests
    };
}