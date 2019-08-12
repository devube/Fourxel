/* Renderer class
*  Hold data needed for rendering.
*  Switch between shader programs.
*  Perform actual rendering.
*/

#pragma once
#include "shader/shaderprogram.hpp"
#include "model.hpp"

class Renderer {
private:
    /* data */

public:
    static ShaderProgram *currentProgram;

    //TODO: Private models
};
