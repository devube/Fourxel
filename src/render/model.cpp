#include "model.hpp"

#include <OBJ_loader.h>
#include <glad/glad.h>

using namespace renderer;

Model *Model::load(const char *path) {
    objl::Loader loader;
    loader.LoadFile(std::string(path));

    Model *model = new Model;
    model->vertices = VertexBufferObject();
    model->vertices.createVBO();
    model->vertices.bindVBO();
    model->vertices.addData(loader.LoadedVertices.data(), loader.LoadedVertices.size() * sizeof(objl::Vertex));
    model->vertices.uploadDataToGPU(GL_STATIC_DRAW);

    model->indeces = ElementBufferObject();
    model->indeces.createEBO();
    model->indeces.bindEBO();
    model->indeces.addData(loader.LoadedIndices.data(), loader.LoadedIndices.size() * sizeof(int));
    model->indeces.uploadDataToGPU(GL_STATIC_DRAW);

    return model;
}
Model::~Model() {
    this->vertices.deleteVBO();
    this->indeces.deleteEBO();
}