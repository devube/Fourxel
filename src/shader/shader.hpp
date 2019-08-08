/* Hight level wrapper of OpenGL shader
*  Loads shader from file, compiles it and is ready to use.
*  Stores shader ID and type in variables.
*  Deletes OpenGL shader when object is destroyed. 
*/

#pragma once
#include <glad/glad.h>

class Shader {
private:
    GLuint _shaderID;
    GLenum _shaderType;

public:
    void loadShaderFromFile(const char* filePath, GLenum shaderType);

    GLuint getShaderID() const;
    GLenum getShaderType() const;

    ~Shader();
};
