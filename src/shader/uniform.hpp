/* High level wrapper of OpenGL uniforms
*  Easly assign values to uniform variables.
*/

#pragma once
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

extern class ShaderProgram;

class Uniform {
private:
    ShaderProgram* _shaderProgram;

    char[] _name;
    GLint _location;

public:
    Uniform();
    Uniform(const char[] name, ShaderProgram* shaderProgram);

    // Setting various uniform types
    Uniform& operator=(const glm::vec2& vector2);
    Uniform& operator=(const glm::vec3& vector3);
    Uniform& operator=(const glm::vec4& vector4);

    Uniform& operator=(const float floatValue);
    Uniform& operator=(const int integerValue);
    Uniform& operator=(const bool boolValue);
    Uniform& operator=(const glm::mat2& matrix);
    Uniform& operator=(const glm::mat3& matrix);
    Uniform& operator=(const glm::mat4& matrix);
};
