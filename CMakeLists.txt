project(platforms-module)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)

add_subdirectory(backends)
add_subdirectory(platforms)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23 CXX_STANDART_REQUIRED ON CXX_EXTENSIONS OFF)