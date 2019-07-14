#include <iostream>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include "basic/windowEvents.hpp"
#include "basic/input.hpp"

#include "renderer/renderer.hpp"

#include "basic/shaders/shader.hpp"
#include "basic/shaders/shaderProgram.hpp"

#include "basic/GPUdata/vertexArrayObject.hpp"
#include "basic/GPUdata/vertexBufferObject.hpp"

#include "geometry/staticGeometry.hpp"

#include "basic/time/timeUtils.hpp"

#include "camera/walkingCamera.hpp"

#include "basic/texture/texture.hpp"
#include "basic/texture/sampler.hpp"

GLFWwindow *window;

ShaderProgram shaderProgram;

WalkingCamera camera(glm::vec3(0.0f, 1.0f, 20.0f),
glm::vec3(0.0f, 1.0f, 19.0f),
glm::vec3(0.0f, 1.0f, 0.0f));

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
    glfwSetWindowSizeCallback(window, onWindowSizeChanged);

    if (!GLAD_GL_VERSION_4_5) {
        std::cout << "Warning: Loaded OpenGL version is not 4.5!" << '\n';
    }

    glViewport(0, 0, 640, 480);

    glClearColor(0.07f, 0.9f, 0.0f, 1.0f);
    glfwSwapInterval(1);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);
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

    shaderProgram.createProgram();
    shaderProgram.addShaderToProgram(*vertexShader);
    shaderProgram.addShaderToProgram(*fragmentShader);
    shaderProgram.linkProgram();
    shaderProgram.useProgram();

    delete vertexShader;
    delete fragmentShader;

    VertexArrayObject *mainVAO = new VertexArrayObject();
    mainVAO->createVAO();
    mainVAO->bindVAO();

    VertexBufferObject *shapesVBO = new VertexBufferObject();
    shapesVBO->createVBO();
    shapesVBO->bindVBO();
    shapesVBO->addData(staticGeometry::cubeVertices, sizeof(staticGeometry::cubeVertices));
    shapesVBO->addData(staticGeometry::pyramidVertices, sizeof(staticGeometry::pyramidVertices));
    shapesVBO->uploadDataToGPU(GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

    VertexBufferObject *texCoordsVBO = new VertexBufferObject();
    texCoordsVBO->createVBO();
    texCoordsVBO->bindVBO();
    texCoordsVBO->addData(staticGeometry::cubeTexCoords, sizeof(staticGeometry::cubeTexCoords), 6);
    texCoordsVBO->addData(staticGeometry::pyramidTexCoords, sizeof(staticGeometry::pyramidTexCoords), 4);
    texCoordsVBO->uploadDataToGPU(GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

    camera.setControls(GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D);

    Texture stoneTexture;
    stoneTexture.loadTexture2D("assets/textures/stone.png");
    stoneTexture.bind();

    Sampler stoneSampler;
    stoneSampler.create();
    stoneSampler.bind();
    stoneSampler.setMinificationFilter(MIN_FILTER_NEAREST);
    stoneSampler.setMagnificationFilter(MAG_FILTER_NEAREST);

    shaderProgram["sampler"] = 0;

    shaderProgram["matrices.projectionMatrix"] = glm::perspective(
    45.0f, // field of view angle (in degrees)
    float(640) / float(480), // aspect ratio
    0.5f, // near plane distance
    1000.0f); // far plane distan

    while (!glfwWindowShouldClose(window)) {
        timeUtils::updateDeltaTimeAndFPS();
        renderScene(mainVAO);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
