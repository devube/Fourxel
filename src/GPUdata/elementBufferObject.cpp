#include "elementBufferObject.hpp"

void ElementBufferObject::createEBO(GLuint reserveSizeBytes) {
    glGenBuffers(1, &_bufferID);
    if (reserveSizeBytes > 0) {
        _rawData.reserve(reserveSizeBytes);
    }
}

void ElementBufferObject::bindEBO(GLenum bufferType) {
    _bufferType = bufferType;
    glBindBuffer(_bufferType, _bufferID);
}

void ElementBufferObject::addData(void* ptrData, GLuint dataSizeBytes,
    GLuint repeat) {
        for (int i = 0; i < repeat; i++) {
            _rawData.insert(_rawData.end(),
            (unsigned char*)ptrData, (unsigned char*)ptrData + dataSizeBytes);
        }
}

void* ElementBufferObject::getDataPointer() {
    return (void*)&_rawData[0];
}

void ElementBufferObject::uploadDataToGPU(GLenum usageHint) {
    glBufferData(_bufferType, _rawData.size(), &_rawData[0], usageHint);
    _uploadedDataSize = (GLuint)_rawData.size();
    _rawData.clear();
}

void* ElementBufferObject::mapBufferToMemory(GLenum usageHint) {
    return glMapBuffer(_bufferType, usageHint);
}

void* ElementBufferObject::mapSubBufferToMemory(GLenum usageHint, GLuint offset, GLuint length) {
    return glMapBufferRange(_bufferType, offset, length, usageHint);
}

void ElementBufferObject::unmapBuffer() {
    glUnmapBuffer(_bufferType);
}

GLuint ElementBufferObject::getBufferID() const {
    return _bufferID;
}

GLuint ElementBufferObject::getBufferSize() const {
    return _uploadedDataSize;
}

void ElementBufferObject::deleteEBO() {
    glDeleteBuffers(1, &_bufferID);
    _rawData.clear();
}
