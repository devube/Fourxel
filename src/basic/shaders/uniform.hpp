#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

#include <string>
#include <vector>

class ShaderProgram;

class Uniform {
public:
    Uniform();
    Uniform(const std::string& name, ShaderProgram* shaderProgram);

    // Family of functions setting vec2 uniforms
    Uniform& operator=(const glm::vec2& vector2);
    void set(const glm::vec2& vector2);
    void set(const glm::vec2* vectors2, int cout = 1);

    // Family of functions setting vec3 uniforms
	Uniform& operator=(const glm::vec3& vector3);
	void set(const glm::vec3& vector3);
	void set(const glm::vec3* vectors3, int count = 1);

	// Family of functions setting vec4 uniforms
	Uniform& operator=(const glm::vec4& vector4);
	void set(const glm::vec4& vector4);
	void set(const glm::vec4* vectors4, int count = 1);

	// Family of functions setting float uniforms
	Uniform& operator=(const float floatValue);
	void set(const float floatValue);
	void set(const float* floatValues, int count = 1);

	// Family of functions setting integer uniforms
	Uniform& operator=(const int integerValue);
	void set(const int integerValue);
	void set(const int* integerValues, int count = 1);

	// Family of functions setting boolean uniforms
	Uniform& operator=(const bool boolValue);
	void set(const bool boolValue);
	void set(const bool* boolValue, int count = 1);

	// Family of functions setting 3x3 matrices uniforms
	Uniform& operator=(const glm::mat3& matrix);
	void set(const glm::mat3& matrix);
	void set(const glm::mat3* matrices, int count = 1);

	// Family of functions setting 4x4 matrices uniforms
	Uniform& operator=(const glm::mat4& matrix);
	void set(const glm::mat4& matrix);
    void set(const glm::mat4* matrices, int count = 1);

private:
    ShaderProgram* _shaderProgram;

    std::string _name;
    int _location;
};
