#include "shaderprogram.hpp"

void ShaderProgram::createProgram() {
    _shaderProgramID = glCreateProgram();
}

void ShaderProgram::addShaderToProgram(const Shader& shader) {
    glAttachShader(_shaderProgramID, shader.getShaderID());
}

void ShaderProgram::linkProgram() {
    glLinkProgram(_shaderProgramID);

    // Check for linking errors
    GLint linkStatus;
    glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE) {
        GLchar infoLogBuffer[512];
        glGetProgramInfoLog(_shaderProgramID, 512, NULL, infoLogBuffer);
        throw std::runtime_error(infoLogBuffer);
    }
}

void ShaderProgram::useProgram() {
    glUseProgram(_shaderProgramID);
}

void ShaderProgram::deleteProgram() {
    glDeleteProgram(_shaderProgramID);
}

GLuint ShaderProgram::getShaderProgramID() const {
    return _shaderProgramID;
}

ShaderProgram::~ShaderProgram() {
    deleteProgram();
}

Uniform& ShaderProgram::operator[](const char[]& varName) {
    if (_uniforms.count(varName) == 0) {
        _uniforms[varName]= Uniform(varName, this);
    }
    return _uniforms[varName];
}
