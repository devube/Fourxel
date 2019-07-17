#version 450 core
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexTexCoord;

uniform struct {
    mat4 projectionMatrix;
    mat4 viewMatrix;
    mat4 modelMatrix;
} matrices;

out vec2 ioVertexTexCoord;

vec4 oVertexPosition;

void main() {

    mat4 mvpMatrix = matrices.projectionMatrix * matrices.viewMatrix * matrices.modelMatrix;

    oVertexPosition = vec4(vertexPosition, 1.0);
    oVertexPosition = mvpMatrix * oVertexPosition;
    gl_Position = oVertexPosition;
    ioVertexTexCoord = vertexTexCoord;
}
