#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include "renderer.hpp"

#include "basic/shaders/shaderProgram.hpp"
#include "basic/time/timeUtils.hpp"

#include "camera/walkingCamera.hpp"

extern ShaderProgram shaderProgram;
extern WalkingCamera camera;
extern GLFWwindow *window;

void renderScene(VertexArrayObject *VAO) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.useProgram();
    VAO->bindVAO();

    shaderProgram["matrices.projectionMatrix"] = glm::perspective(
    45.0f, // field of view angle (in degrees)
    float(640) / float(480), // aspect ratio
    0.5f, // near plane distance
    1000.0f); // far plane distan
    shaderProgram["matrices.viewMatrix"] = camera.getViewMatrix();

    for (int i = 0; i < 10; i++) {
        glm::mat4 modelMatrixCube = glm::mat4(1.0);
        modelMatrixCube = glm::translate(modelMatrixCube, glm::vec3(0.0f, 1.0f, 1.5f * i));

        shaderProgram["matrices.modelMatrix"] = modelMatrixCube;
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    int winPosX, winPosY, winWidth, winHeight;
    glfwGetWindowPos(window, &winPosX, &winPosY);
    glfwGetWindowSize(window, &winWidth, &winHeight);
    camera.setWindowCenterPosition(glm::dvec2(winPosX + winWidth / 2, winPosY + winHeight / 2));

    camera.update();
}
