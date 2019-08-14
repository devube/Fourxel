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

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // normal
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // uv
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(1);

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

        models[i]->indices = new GPUdata::ElementBufferObject();
        models[i]->indices->addData(loader.LoadedIndices.data(), loader.LoadedIndices.size() * sizeof(int));
        models[i]->indices->uploadDataToGPU(GL_STATIC_DRAW);

        // position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // normal
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);

        // uv
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    return models;
}

Model::~Model() {
    delete this->vertices;
    delete this->indices;
}


GLuint Model::get_indieces() {
    return this->indices->getBufferID();
}
size_t Model::get_indieces_size() {
    return this->indices->getBufferSize();
}