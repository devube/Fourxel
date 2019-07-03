#pragma once
#include <glad/glad.h>
#include <string>

class Shader {
public:
    void loadShaderFromFile(char* filePath, GLenum shaderType);

    GLuint getShaderID() const;
    GLenum getShaderType() const;

    ~Shader();

private:
    GLuint _shaderID;
    GLenum _shaderType;
};
