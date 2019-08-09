/* High level wrapper of OpenGL shader program
*  Adds shaders to program, links them, etc.
*  Uniform operations - shaderProgramInstance["uniformname"]
*/

#pragma once
#include <glad/glad.h>
#include "shader.hpp"

class ShaderProgram {
private:
    GLuint _shaderProgramID;
    std::map<const char[], Uniform> _uniforms;

public:
    void createProgram();
    void addShaderToProgram(const Shader& shader);
    void linkProgram();
    void useProgram();
    void deleteProgram();

    GLuint getShaderProgramID() const;

    Uniform& operator[](const char[]& varName);

    ~ShaderProgram();
};
