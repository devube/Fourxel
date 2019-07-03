#include "shaderProgram.hpp"
#include <glad/glad.h>
#include <stdexcept>
#include <string>

void ShaderProgram::createProgram() {
    _shaderProgramID = glCreateProgram();
}

void ShaderProgram::addShaderToProgram(const Shader& shader) {
    glAttachShader(_shaderProgramID, shader.getShaderID());
}

void ShaderProgram::linkProgram() {
    glLinkProgram(_shaderProgramID);

    GLint linkStatus;
    glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, &linkStatus);

    if(linkStatus == GL_FALSE) {
        GLchar infoLogBuffer[512];
        glGetProgramInfoLog(_shaderProgramID, 512, NULL, infoLogBuffer);
        throw std::runtime_error(infoLogBuffer);
    }
}

void ShaderProgram::useProgram() {
    glUseProgram(_shaderProgramID);
}

GLuint ShaderProgram::getShaderProgramID() const {
    return _shaderProgramID;
}
