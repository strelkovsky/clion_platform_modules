target_link_libraries(${PROJECT_NAME} PRIVATE glfw user32 gdi32 opengl32 shell32)
target_sources(${PROJECT_NAME} PRIVATE window.cpp window_events.cpp window_factory.cpp)