#include "input.hpp"

extern GLFWwindow *window;

void keyCallback(GLFWwindow* window, int key,
    int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

bool keyPressed(int keyCode) {
    return glfwGetKey(window, keyCode) == GLFW_PRESS;
}

glm::dvec2 getCursorPosition() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return glm::dvec2(xpos, ypos);
}

void setCursorPosition(double posX, double posY) {
    glfwSetCursorPos(window, posX, posY);
}
