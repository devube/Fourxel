#include "renderer.hpp"

void renderScene(ShaderProgram *shaderProgram, VertexArrayObject *VAO) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram->useProgram();
    VAO->bindVAO();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLE_STRIP, 3, 4);
}
