#pragma once

#include <cstdio>
#include <GPUdata/vertexBufferObject.hpp>
#include <GPUdata/elementBufferObject.hpp>

namespace renderer {
    class Model {
    private:
        VertexBufferObject vertices;
        ElementBufferObject indeces;

    public:
        static Model *load(const char *path);

        ~Model();
    };
}