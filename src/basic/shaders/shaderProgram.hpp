#pragma once
#include "shader.hpp"

class ShaderProgram {
public:
    void createProgram();
    void addShaderToProgram(const Shader& shader);
    void linkProgram();
    void useProgram();
    // void deleteProgram();

    GLuint getShaderProgramID() const;
/*
    Uniform& operator[](const std::string& varName);
    void setModelAndNormalMatrix(const std::string& modelMatrixName,
        const std::string& normalMatrixName, const glm::mat4& modelMatrix);
*/
private:
    // Uniform& getUniform(const std::string& varName);

    GLuint _shaderProgramID;
    // std::map<std::string, Uniform> _Uniforms;
};
