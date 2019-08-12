#include "model.hpp"

#include <OBJ_loader.h>
#include <glad/glad.h>

using namespace renderer;

Model *Model::load(const char *path) {
    objl::Loader loader;
    loader.LoadFile(std::string(path));

    Model *model = new Model;
    model->vertices = new GPUdata::VertexBufferObject();
    model->vertices->addData(loader.LoadedVertices.data(), loader.LoadedVertices.size() * sizeof(objl::Vertex));
    model->vertices->uploadDataToGPU(GL_STATIC_DRAW);

    model->indices = new GPUdata::ElementBufferObject();
    model->indices->addData(loader.LoadedIndices.data(), loader.LoadedIndices.size() * sizeof(int));
    model->indices->uploadDataToGPU(GL_STATIC_DRAW);

    return model;
}
Model::~Model() {
    delete this->vertices;
    delete this->indices;
}
