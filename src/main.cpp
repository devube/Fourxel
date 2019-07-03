#include <iostream>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include "basic/windowEvents.hpp"
#include "basic/input.hpp"

#include "basic/renderer.hpp"

#include "basic/shaders/shader.hpp"
#include "basic/shaders/shaderProgram.hpp"

#include "basic/GPUdata/vertexArrayObject.hpp"
#include "basic/GPUdata/vertexBufferObject.hpp"

GLFWwindow *window;

void initGLFWandGlad() {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        throw std::runtime_error("Error while initializing GLFW! Possible solution: Check graphics drivers.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 4.5
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    window = glfwCreateWindow(640, 480, "Gute gra", NULL, NULL);
    if (!window) {
        throw std::runtime_error("Error while creating window or OpenGL context! Possible solution: Check graphics drivers.");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize OpenGL context! Possible solution: Check graphics drivers.");
    }
    glfwSetKeyCallback(window, keyCallback);

    if (!GLAD_GL_VERSION_4_5) {
        std::cout << "Warning: Loaded OpenGL version is not 4.5!" << '\n';
    }

    glClearColor(0.07f, 0.03f, 0.56f, 1.0f);
    glfwSwapInterval(1);
}

int main(int argc, char const *argv[]) {
    try {
        // Init GLFW, OpenGL, create window and context
        initGLFWandGlad();
    } catch(std::runtime_error e) {
        std::cerr << "ERROR! " << e.what() << '\n';
    }

    Shader *vertexShader = new Shader();
    Shader *fragmentShader = new Shader();

    vertexShader->loadShaderFromFile("vertex.glsl", GL_VERTEX_SHADER);
    fragmentShader->loadShaderFromFile("fragment.glsl", GL_FRAGMENT_SHADER);

    ShaderProgram *shaderProgram = new ShaderProgram();

    shaderProgram->createProgram();
    shaderProgram->addShaderToProgram(*vertexShader);
    shaderProgram->addShaderToProgram(*fragmentShader);
    shaderProgram->linkProgram();
    shaderProgram->useProgram();

    delete vertexShader;
    delete fragmentShader;

    VertexArrayObject *mainVAO = new VertexArrayObject();
    mainVAO->createVAO();
    mainVAO->bindVAO();

    glm::vec3 vTriangle[] = {
        glm::vec3(-0.4f, 0.1f, 0.0f),
        glm::vec3(0.4f, 0.1f, 0.0f),
        glm::vec3(0.0f, 0.7f, 0.0f)
    };
    glm::vec3 vQuad[] = {
        glm::vec3(-0.2f, -0.1f, 0.0f),
        glm::vec3(-0.2f, -0.6f, 0.0f),
        glm::vec3(0.2f, -0.1f, 0.0f),
        glm::vec3(0.2f, -0.6f, 0.0f)
    };

    VertexBufferObject *shapesVBO = new VertexBufferObject();
    shapesVBO->createVBO();
    shapesVBO->bindVBO();
    shapesVBO->addData(vTriangle, sizeof(glm::vec3) * 3);
    shapesVBO->addData(vQuad, sizeof(glm::vec3) * 4);
    shapesVBO->uploadDataToGPU(GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)0);

    while (!glfwWindowShouldClose(window)) {
        renderScene(shaderProgram, mainVAO);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
