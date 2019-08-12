#pragma once
#include <glad/glad.h>
#include <vector>


namespace GPUdata {
    /**
     * @brief Abstract class for GPU memory
     * Do NOT create instance of this class, use ElementBufferObject or VertexBufferObject instead
     * 
     */
    class BufferObject {
    public:
        /**
         * @brief Creates new buffer
         * 
         * @param reserveSizeBytes 
         */
        void create(GLuint reserveSizeBytes = 0);
        /**
         * @brief Binds buffer
         * 
         * @param bufferType 
         */
        void bind(GLenum bufferType);

        /**
         * @brief Adds data to buffer
         * 
         * @param ptrData Pointer to added data
         * @param dataSizeBytes Sizeof added data
         * @param repeat How many times adds added data
         */
        void addData(void* ptrData, GLuint dataSizeBytes, GLuint repeat = 1);
        /**
         * @brief Get the data pointer object
         * 
         * @return void* Pointer to data
         */
        void* getDataPointer();
        /**
         * @brief Sends added data to GPU
         * 
         * @param usageHint 
         */
        void uploadDataToGPU(GLenum usageHint);

        void* mapBufferToMemory(GLenum usageHint);
        void* mapSubBufferToMemory(GLenum usageHint, GLuint offset, GLuint length);
        void unmapBuffer();

        /**
         * @brief Get the Buffer ID object
         * 
         * @return GLuint 
         */
        GLuint getBufferID() const;
        GLuint getBufferSize() const;

        BufferObject(GLenum bufferType);
        ~BufferObject();

    private:
        GLuint _bufferID = 0;
        int _bufferType;
        GLuint _uploadedDataSize;
        std::vector<unsigned char> _rawData;
    };

}
