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

    model->indeces = new GPUdata::ElementBufferObject();
    model->indeces->addData(loader.LoadedIndices.data(), loader.LoadedIndices.size() * sizeof(int));
    model->indeces->uploadDataToGPU(GL_STATIC_DRAW);

    return model;
}

Model **Model::load_many(const char **path, size_t count) {
    objl::Loader loader;
    Model **models = new Model*[count];

    for (size_t i = 0; i < count; i++) {
        loader.LoadFile(std::string(path[i]));

        models[i] = new Model;
        models[i]->vertices = new GPUdata::VertexBufferObject();
        models[i]->vertices->addData(loader.LoadedVertices.data(), loader.LoadedVertices.size() * sizeof(objl::Vertex));
        models[i]->vertices->uploadDataToGPU(GL_STATIC_DRAW);

        models[i]->indeces = new GPUdata::ElementBufferObject();
        models[i]->indeces->addData(loader.LoadedIndices.data(), loader.LoadedIndices.size() * sizeof(int));
        models[i]->indeces->uploadDataToGPU(GL_STATIC_DRAW);
    }

    return models;
}

Model::~Model() {
    delete this->vertices;
    delete this->indeces;
}