#include "shader.hpp"
#include <stdexcept>
#include <string>

#include "basic/files/files.h"

void Shader::loadShaderFromFile(char* filePath, GLenum shaderType) {

    char* shaderSrc = strFromFile(filePath);

    _shaderID = glCreateShader(shaderType);

    glShaderSource(_shaderID, 1, &shaderSrc, NULL);
    glCompileShader(_shaderID);

    GLint compilationStatus;
    glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &compilationStatus);

    if(compilationStatus == GL_FALSE) {
        GLchar infoLogBuffer[512];
        glGetShaderInfoLog(_shaderID, 512, NULL, infoLogBuffer);
        throw std::runtime_error(infoLogBuffer);
    }

    _shaderType = shaderType;
}

GLuint Shader::getShaderID() const {
    return _shaderID;
}

GLenum Shader::getShaderType() const {
    return _shaderType;
}

Shader::~Shader() {
    glDeleteShader(_shaderID);
}
