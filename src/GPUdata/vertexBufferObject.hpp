#pragma once
#include <glad/glad.h>
#include <vector>

#include "BufferObject.hpp"

namespace GPUdata {
    class VertexBufferObject : public BufferObject {
    public:
        VertexBufferObject(GLenum type = GL_ARRAY_BUFFER);
    };
}

