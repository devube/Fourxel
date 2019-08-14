#include "gameloop.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window/window.hpp>

#include <render/model.hpp>
#include <render/renderer3d.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

void gameloop::gameloop() {

    renderer::Model *cube = renderer::Model::load("assets/cube.obj");
    Fourxel::Graphics::Renderer3d rend;

    glm::mat4 world(1);
    glm::mat4 transform(1);
    glm::vec3 position(0);
    
    while (!glfwWindowShouldClose(Window::GLFWwindowptr)) {
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        rend.render_model(cube, glm::value_ptr(world), glm::value_ptr(transform), glm::value_ptr(position));

        glfwPollEvents();
        glfwSwapBuffers(Window::GLFWwindowptr);
    }
} // void gameloop::gameloop()
