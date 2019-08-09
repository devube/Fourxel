/* Renderer class
*  Hold data needed for rendering.
*  Switch between shader programs.
*  Perform actual rendering.
*/

#pragma once
#include "shader/shaderprogram.hpp"

class Renderer {
private:
    /* data */

public:
    static ShaderProgram *currentProgram;
};
