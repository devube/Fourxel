#include "shaderProgram.hpp"
#include <glad/glad.h>
#include <stdexcept>
#include <string>

ShaderProgram::~ShaderProgram() {
    deleteProgram();
}

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

void ShaderProgram::deleteProgram() {
    glDeleteProgram(_shaderProgramID);
}

GLuint ShaderProgram::getShaderProgramID() const {
    return _shaderProgramID;
}

Uniform& ShaderProgram::operator[] (const std::string& varName) {
    if (_uniforms.count(varName) == 0) {
        _uniforms[varName] = Uniform(varName, this);
    }

    return _uniforms[varName];
}

// void ShaderProgram::setModelAndNormalMatrix(const glm::mat4& modelMatrix) {
//     (*this)[ShaderConstants::modelMatrix()] = modelMatrix;
//     (*this)["matrices.normalMatrix"] == glm::transpose(glm::inverse(glm::mat3(modelMatrix)));
// }
