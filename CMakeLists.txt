cmake_minimum_required(VERSION 3.0.0)
project(Fourxel VERSION 0.1.0)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)

include_directories(oldsrc include modules)

add_executable(Fourxel
    oldsrc/basic/files/files.c
    oldsrc/basic/GPUdata/vertexArrayObject.cpp
    oldsrc/basic/GPUdata/vertexBufferObject.cpp
    oldsrc/basic/shaders/shader.cpp
    oldsrc/basic/shaders/shaderProgram.cpp
    oldsrc/basic/shaders/uniform.cpp
    oldsrc/basic/texture/sampler.cpp
    oldsrc/basic/texture/texture.cpp
    oldsrc/basic/time/timeUtils.cpp
    oldsrc/basic/input.cpp
    oldsrc/basic/windowEvents.cpp

    oldsrc/camera/walkingCamera.cpp

    oldsrc/geometry/staticGeometry.cpp
    
    oldsrc/glad/glad.c
    
    oldsrc/renderer/renderer.cpp

    oldsrc/main.cpp
)

target_link_libraries(Fourxel
    PkgConfig::GLFW
    PkgConfig::GL
)

configure_file(fragment.glsl fragment.glsl COPYONLY)
configure_file(vertex.glsl vertex.glsl COPYONLY)
configure_file(assets/models/cube.mdl assets/models/cube.mdl COPYONLY)
configure_file(assets/textures/stone.png assets/textures/stone.png COPYONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})