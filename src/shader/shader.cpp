#include "shader.hpp"
#include "files/readfile.hpp"
#include "log/log.hpp"

void Shader::loadShaderFromFile(const char* filePath, GLenum shaderType) {

    // Read shader source to C string
    char* shaderSrc = strFromFile(filePath);

    _shaderID = glCreateShader(shaderType);

    glShaderSource(_shaderID, 1, &shaderSrc, NULL);
    glCompileShader(_shaderID);


    // Check for shader compilation errors
    GLint compilationStatus;
    glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &compilationStatus);
    if (compilationStatus == GL_FALSE) {
        GLchar infoLogBuffer[512];
        glGetShaderInfoLog(_shaderID, 512, NULL, infoLogBuffer);
        _log::error(infoLogBuffer, __FILE__, __LINE__);
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
