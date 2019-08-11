cmake_minimum_required(VERSION 3.0.0)
project(Fourxel VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)

include_directories(src include modules)

file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)
add_executable(Fourxel ${SRC_FILES})

target_link_libraries(Fourxel
    PkgConfig::GLFW
    PkgConfig::GL
)

configure_file(fragment.glsl fragment.glsl COPYONLY)
configure_file(vertex.glsl vertex.glsl COPYONLY)
configure_file(assets/models/cube.obj assets/models/cube.obj COPYONLY)
configure_file(assets/textures/stone.png assets/textures/stone.png COPYONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})