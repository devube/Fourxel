#include "init.hpp"
#include <GLFW/glfw3.h>
#include "window/window.hpp"

void init::initGLFW(const int width, const int height, const char[] title) {
    //glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        throw std::runtime_error("Error while initializing GLFW! Possible solution: Check graphics drivers.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 4.5
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    Window::GLFWwindowptr = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!Window::GLFWwindowptr) {
        throw std::runtime_error("Error while creating window or OpenGL context! Possible solution: Check graphics drivers.");
    }

    glfwMakeContextCurrent(Window::GLFWwindowptr);

    //glfwSetKeyCallback(Window::GLFWwindowptr, keyCallback);
    //glfwSetWindowSizeCallback(Window::GlFWwindowptr, onWindowSizeChanged);

    // make cursor invisible and lock it in center of window
    glfwSetInputMode(Window::GLFWwindowptr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
