#pragma once
#include <glad/glad.h>

class VertexArrayObject {
public:
    void createVAO();
    void bindVAO();

private:
    GLuint _arrayID;
};
