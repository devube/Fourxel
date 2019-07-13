#pragma once

class timeUtils {
public:
    static void updateDeltaTimeAndFPS();
    static float sof(float valuePerSecond);

private:
    static float _timeDelta, _lastFrameTime, _nextFPS, _FPS, _lastFrameTimeFPS;
};
