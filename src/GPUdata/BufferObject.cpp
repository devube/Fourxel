#include "BufferObject.hpp"

using namespace GPUdata;

void BufferObject::create(GLuint reserveSizeBytes) {
    glGenBuffers(1, &_bufferID);
    if (reserveSizeBytes > 0) {
        _rawData.reserve(reserveSizeBytes);
    }
}

void BufferObject::bind(GLenum bufferType) {
    _bufferType = bufferType;
    glBindBuffer(_bufferType, _bufferID);
}

void BufferObject::addData(void* ptrData, GLuint dataSizeBytes,
    GLuint repeat) {
        for (int i = 0; i < repeat; i++) {
            _rawData.insert(_rawData.end(),
            (unsigned char*)ptrData, (unsigned char*)ptrData + dataSizeBytes);
        }
}

void* BufferObject::getDataPointer() {
    return (void*)&_rawData[0];
}

void BufferObject::uploadDataToGPU(GLenum usageHint) {
    glBufferData(_bufferType, _rawData.size(), &_rawData[0], usageHint);
    _uploadedDataSize = (GLuint)_rawData.size();
    _rawData.clear();
}

void* BufferObject::mapBufferToMemory(GLenum usageHint) {
    return glMapBuffer(_bufferType, usageHint);
}

void* BufferObject::mapSubBufferToMemory(GLenum usageHint, GLuint offset, GLuint length) {
    return glMapBufferRange(_bufferType, offset, length, usageHint);
}

void BufferObject::unmapBuffer() {
    glUnmapBuffer(_bufferType);
}

GLuint BufferObject::getBufferID() const {
    return _bufferID;
}

GLuint BufferObject::getBufferSize() const {
    return _uploadedDataSize;
}

BufferObject::BufferObject(GLenum bufferType) {
    this->create();
    this->bind(bufferType);
}

BufferObject::~BufferObject() {
    glDeleteBuffers(1, &_bufferID);
    _rawData.clear();
}
