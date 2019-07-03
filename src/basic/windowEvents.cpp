#include "windowEvents.hpp"

// Error callback for GLFW
void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

void onWindowSizeChanged(GLFWwindow* window, int width, int height) {
    // Change OpenGL view port to window size
    glViewport(0, 0, width, height);
}
