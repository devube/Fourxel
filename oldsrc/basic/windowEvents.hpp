#pragma once
#include <cstdio>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Error callback for GLFW
void errorCallback(int error, const char* description);

void onWindowSizeChanged(GLFWwindow* window, int width, int height);
