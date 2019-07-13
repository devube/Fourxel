#version 450 core
layout(location = 0) out vec4 outputColor;

in vec3 ioVertexColor;

void main() {
    outputColor = vec4(ioVertexColor, 1.0f);
}
