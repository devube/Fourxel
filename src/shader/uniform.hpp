/* High level wrapper of OpenGL uniforms
*  Easly assign values to uniform variables.
*/

#pragma once

extern class ShaderProgram;

class Uniform {
private:
    ShaderProgram* _shaderProgram;

    char[] _name;
    GLint _location;

public:
    Uniform();
};
