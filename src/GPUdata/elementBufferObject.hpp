#pragma once
#include <glad/glad.h>
#include <vector>

class ElementBufferObject {
public:
    void createEBO(GLuint reserveSizeBytes = 0);
    void bindEBO(GLenum bufferType = GL_ARRAY_BUFFER);

    void addData(void* ptrData, GLuint dataSizeBytes, GLuint repeat = 1);
    void* getDataPointer();
    void uploadDataToGPU(GLenum usageHint);

    void* mapBufferToMemory(GLenum usageHint);
    void* mapSubBufferToMemory(GLenum usageHint, GLuint offset, GLuint length);
    void unmapBuffer();

    GLuint getBufferID() const;
    GLuint getBufferSize() const;

    void deleteEBO();

private:
    GLuint _bufferID = 0;
    int _bufferType;
    GLuint _uploadedDataSize;
    std::vector<unsigned char> _rawData;
};
