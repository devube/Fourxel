#include "model.hpp"

#include <OBJ_loader.h>
#include <glad/glad.h>

using namespace renderer;

Model *Model::load(const char *path) {
    objl::Loader loader;
    loader.LoadFile(std::string(path));

    Model *model = new Model;
    model->vbo = VertexBufferObject();
    model->vbo.createVBO();
    model->vbo.bindVBO();
    model->vbo.addData(loader.LoadedVertices.data(), loader.LoadedVertices.size() * sizeof(objl::Vertex));
    model->vbo.uploadDataToGPU(GL_STATIC_DRAW);

    return model;
}
Model::~Model() {
    this->vbo.deleteVBO();
}