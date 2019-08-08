/* Init functions */

#pragma once

namespace init {
    void initGLFW(const int width, const int height, const char[] title);
    void initOpenGL();
    void initShaders();
    void initVertexBuffers();
    void initTextures();
} /* namespace init */
