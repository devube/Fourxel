#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace staticGeometry {
    // Cube with unit size
    extern glm::vec3 cubeVertices[36];
    extern glm::vec2 cubeTexCoords[6];
    extern glm::vec3 cubeFaceColors[6];

    // A simple pyramid with unit size
    extern glm::vec3 pyramidVertices[12];
    extern glm::vec2 pyramidTexCoords[3];
    extern glm::vec3 pyramidFaceColors[3];
}
