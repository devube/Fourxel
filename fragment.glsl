#version 450 core
layout(location = 0) out vec4 outputColor;

in vec2 ioVertexTexCoord;

uniform sampler2D gSampler;

void main() {
    vec4 texColor = texture(gSampler, ioVertexTexCoord);
    outputColor = texColor;
}
