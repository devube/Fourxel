#include "init.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <window/window.hpp>
#include <shader/shader.hpp>
#include <log/log.hpp>
#include <shader/shaderprogram.hpp>
#include <render/renderer.hpp>

void init::initGLFW(const int width, const int height, const char title[]) {
    //glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        _log::error("Error while initializing GLFW! Possible solution: Check graphics drivers.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 4.5
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    Window::GLFWwindowptr = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!Window::GLFWwindowptr) {
        _log::error("Error while creating window or OpenGL context! Possible solution: Check graphics drivers.");
    }

    glfwMakeContextCurrent(Window::GLFWwindowptr);

    //glfwSetKeyCallback(Window::GLFWwindowptr, keyCallback);
    //glfwSetWindowSizeCallback(Window::GlFWwindowptr, onWindowSizeChanged);

    glfwSwapInterval(1);

    // make cursor invisible and lock it in center of window
    glfwSetInputMode(Window::GLFWwindowptr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
} // void init::initGLFW()

void init::initOpenGL() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        _log::error("Failed to initialize OpenGL context! Possible solution: Check graphics drivers.");
    }

    int width, height;
    glfwGetFramebufferSize(Window::GLFWwindowptr, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.07f, 0.3f, 0.8f, 1.0f);

    glEnable(GL_DEPTH_TEST);
} // void init::initOpenGL()

void init::initShaders() {
    // Create high level shader objects
    Shader *vertexShader = new Shader();
    Shader *fragmentShader = new Shader();

    // Load shaders from files and compile them
    vertexShader->loadShaderFromFile("vertex.glsl", GL_VERTEX_SHADER);
    fragmentShader->loadShaderFromFile("fragment.glsl", GL_FRAGMENT_SHADER);

    // Initialize shader program
    Renderer::currentProgram = new ShaderProgram();
    Renderer::currentProgram->createProgram();
    Renderer::currentProgram->addShaderToProgram(*vertexShader);
    Renderer::currentProgram->addShaderToProgram(*fragmentShader);
    Renderer::currentProgram->linkProgram();
    Renderer::currentProgram->useProgram();

    // Shader instances are not needed now, because are added to program
    delete vertexShader;
    delete fragmentShader;
} // void init::initShaders()

void init::initModels() {
    
} // void init::initModels()
