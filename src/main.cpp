#include "init/init.hpp"
#include "gameloop/gameloop.hpp"
#include "terminate/terminate.hpp"

int main(int argc, char const *argv[]) {
    // width, height, title
    init::initGLFW(640, 480, "Gute gra");
    init::initOpenGL();
    init::initShaders();
    init::initVertexBuffers();
    init::initTextures();

    gameloop::gameloop();

    terminate::termGLFW();

    return 0;
} /* int main() */
