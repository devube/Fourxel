#include "uniform.hpp"
#include "shaderprogram.hpp"
#include "log/log.hpp"
#include <string>

Uniform::Uniform() : _shaderProgram(nullptr), _location(-1) {}

Uniform::Uniform(char *name, ShaderProgram* shaderProgram) :
    _name(name), _shaderProgram(shaderProgram) {
    _location = glGetUniformLocation(_shaderProgram->getShaderProgramID(), _name);
    if (_location == -1) {
        std::string message(name);
        message.append( "uniform does not exist!");

        _log::warning(message.c_str());
    }
}


Uniform& Uniform::operator=(const float floatValue) {
    glUniform1fv(_location, 1, (GLfloat*)&floatValue);
    return *this;
}

Uniform& Uniform::operator=(const int integerValue) {
    glUniform1iv(_location, 1, (GLint*)&integerValue);
    return *this;
}

Uniform& Uniform::operator=(const bool boolValue) {
    glUniform1i(_location, boolValue);
    return *this;
}


Uniform& Uniform::operator=(const glm::vec2& vector2) {
    glUniform2fv(_location, 1, (GLfloat*)&vector2);
    return *this;
}

Uniform& Uniform::operator=(const glm::vec3& vector3) {
    glUniform3fv(_location, 1, (GLfloat*)&vector3);
    return *this;
}

Uniform& Uniform::operator=(const glm::vec4& vector4) {
    glUniform4fv(_location, 1, (GLfloat*)&vector4);
    return *this;
}


Uniform& Uniform::operator=(const glm::mat2& matrix) {
    glUniformMatrix2fv(_location, 1, false, (GLfloat*)&matrix);
    return *this;
}

Uniform& Uniform::operator=(const glm::mat3& matrix) {
    glUniformMatrix3fv(_location, 1, false, (GLfloat*)&matrix);
    return *this;
}

Uniform& Uniform::operator=(const glm::mat4& matrix) {
    glUniformMatrix4fv(_location, 1, false, (GLfloat*)&matrix);
    return *this;
}
