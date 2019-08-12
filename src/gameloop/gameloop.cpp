#include "gameloop.hpp"
#include <GLFW/glfw3.h>
#include <window/window.hpp>

void gameloop::gameloop() {
    while (glfwWindowShouldClose(Window::GLFWwindowptr)) {
        glfwPollEvents();
        glfwSwapBuffers(Window::GLFWwindowptr);
    }
} // void gameloop::gameloop()
