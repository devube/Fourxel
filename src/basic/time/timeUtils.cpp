#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "timeUtils.hpp"

float timeUtils::_timeDelta = 0.0f, timeUtils::_lastFrameTime = 0.0f,
timeUtils::_nextFPS = 0.0f, timeUtils::_FPS = 0.0f, timeUtils::_lastFrameTimeFPS = 0.0f;

void timeUtils::updateDeltaTimeAndFPS() {
    const double currentTime = glfwGetTime();
    _timeDelta = currentTime - _lastFrameTime;
    _lastFrameTime = currentTime;
    _nextFPS++;

    if (currentTime - _lastFrameTimeFPS > 1.0) {
        _lastFrameTimeFPS = currentTime;
        _FPS = _nextFPS;
        _nextFPS = 0;
    }
}

float timeUtils::sof(float valuePerSecond) {
    return _timeDelta * valuePerSecond;
}
