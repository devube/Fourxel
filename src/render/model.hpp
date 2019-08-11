#pragma once

#include <cstdio>
#include <GPUdata/vertexBufferObject.hpp>

namespace renderer {
    class Model {
    private:
        VertexBufferObject vbo;

    public:
        static Model *load(const char *path);

        ~Model();
    };
}