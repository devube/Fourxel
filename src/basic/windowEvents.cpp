#include "windowEvents.hpp"
#include "basic/shaders/shaderProgram.hpp"
#include <glm/ext/matrix_clip_space.hpp>

extern ShaderProgram shaderProgram;

// Error callback for GLFW
void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

void onWindowSizeChanged(GLFWwindow* window, int width, int height) {
    // Change OpenGL view port to window size
    glViewport(0, 0, width, height);

    shaderProgram["matrices.projectionMatrix"] = glm::perspective(
    45.0f, // field of view angle (in degrees)
    float(width) / float(height), // aspect ratio
    0.5f, // near plane distance
    1000.0f); // far plane distan
}
