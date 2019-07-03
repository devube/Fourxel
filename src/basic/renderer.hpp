#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GPUdata/vertexArrayObject.hpp"
#include "shaders/shaderProgram.hpp"

void renderScene(ShaderProgram *shaderProgram, VertexArrayObject *VAO);
