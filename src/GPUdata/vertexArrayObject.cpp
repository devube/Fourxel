#include "vertexArrayObject.hpp"

void VertexArrayObject::createVAO() {
    glGenVertexArrays(1, &_arrayID);
}

void VertexArrayObject::bindVAO() {
    glBindVertexArray(_arrayID);
}
