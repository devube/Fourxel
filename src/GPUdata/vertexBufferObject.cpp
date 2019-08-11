#include "vertexBufferObject.hpp"

void VertexBufferObject::createVBO(GLuint reserveSizeBytes) {
    glGenBuffers(1, &_bufferID);
    if (reserveSizeBytes > 0) {
        _rawData.reserve(reserveSizeBytes);
    }
}

void VertexBufferObject::bindVBO(GLenum bufferType) {
    _bufferType = bufferType;
    glBindBuffer(_bufferType, _bufferID);
}

void VertexBufferObject::addData(void* ptrData, GLuint dataSizeBytes,
    GLuint repeat) {
        for (int i = 0; i < repeat; i++) {
            _rawData.insert(_rawData.end(),
            (unsigned char*)ptrData, (unsigned char*)ptrData + dataSizeBytes);
        }
}

void* VertexBufferObject::getDataPointer() {
    return (void*)&_rawData[0];
}

void VertexBufferObject::uploadDataToGPU(GLenum usageHint) {
    glBufferData(_bufferType, _rawData.size(), &_rawData[0], usageHint);
    _uploadedDataSize = (GLuint)_rawData.size();
    _rawData.clear();
}

void* VertexBufferObject::mapBufferToMemory(GLenum usageHint) {
    return glMapBuffer(_bufferType, usageHint);
}

void* VertexBufferObject::mapSubBufferToMemory(GLenum usageHint, GLuint offset, GLuint length) {
    return glMapBufferRange(_bufferType, offset, length, usageHint);
}

void VertexBufferObject::unmapBuffer() {
    glUnmapBuffer(_bufferType);
}

GLuint VertexBufferObject::getBufferID() const {
    return _bufferID;
}

GLuint VertexBufferObject::getBufferSize() const {
    return _uploadedDataSize;
}

void VertexBufferObject::deleteVBO() {
    glDeleteBuffers(1, &_bufferID);
    _rawData.clear();
}
