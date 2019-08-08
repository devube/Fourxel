#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

// GLFW key callback
void keyCallback(GLFWwindow* window, int key,
    int scancode, int action, int mods);

bool keyPressed(int keyCode);

glm::dvec2 getCursorPosition();

void setCursorPosition(double posX, double posY);
