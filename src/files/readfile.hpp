/* Functions for reading files */

#pragma once

#include <glm/vec3.hpp>


#ifdef __cplusplus
extern "C" {
#endif
    // Read file and return it as a C string
    char* strFromFile(const char* path);
#ifdef __cplusplus
}
#endif

// Read file and return it as an array (pointer to first element) of vertices
glm::vec3* readModelFile(const char* path);
//TODO: 4D models
