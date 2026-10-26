#pragma once

namespace core::base
{
    class WindowEvents
    {
    public:
        virtual auto update() -> void = 0;
    };
}