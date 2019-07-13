#version 450 core
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

uniform struct {
    mat4 projectionMatrix;
    mat4 viewMatrix;
    mat4 modelMatrix;
} matrices;

out vec3 ioVertexColor;

vec4 oVertexPosition;
// mat4 transform;

void main() {
    ioVertexColor = vertexColor;
    // transform[0] = vec4(1.0, 0.0, 0.0, 0.0); // x
    // transform[1] = vec4(0.0, 1.0, 0.0, 0.0); // y
    // transform[2] = vec4(0.0, 0.0, 1.0, 0.0); // z
    // transform[3] = vec4(0.0, 0.0, 0.0, 1.0); // w

    mat4 mvpMatrix = matrices.projectionMatrix * matrices.viewMatrix * matrices.modelMatrix;

    oVertexPosition = vec4(vertexPosition, 1.0);
    oVertexPosition = mvpMatrix * oVertexPosition;
    gl_Position = oVertexPosition;
}
