#include "window_factory.hpp"
#include "window.hpp"

namespace backends::glfw
{
    auto WindowFactory::create_window() -> std::unique_ptr<core::base::Window>
    {
        return std::make_unique<Window>();
    }
}
