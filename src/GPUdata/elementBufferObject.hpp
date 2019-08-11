#pragma once
#include <glad/glad.h>
#include <vector>

#include "BufferObject.hpp"

namespace GPUdata {
    class ElementBufferObject : public BufferObject {
    public:
        ElementBufferObject(GLenum type = GL_ELEMENT_ARRAY_BUFFER);
    };
}

