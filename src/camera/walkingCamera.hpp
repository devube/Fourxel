#pragma once

#include <glm/geometric.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class WalkingCamera {
public:
    WalkingCamera(const glm::vec3& position, const glm::vec3& viewPoint,
    const glm::vec3& upVector, float moveSpeed = 10.0f, float mouseSensitivity = 0.15f);

    void setWindowCenterPosition(glm::dvec2 windowCenterPosition);
    void setMoveSpeed(float moveSpeed);
    void setMouseSensitivity(float sensitivity);
    void setControls(int forwardKeyCode, int backwardKeyCode,
        int leftKeyCode, int rightKeyCode);

    glm::mat4 getViewMatrix() const;
    void update();

private:
    void moveBy(float distance);
    void strafeBy(float distance);
    void rotateHorizontally(float angleInDegrees);
    void rotateVertically(float angleInDegrees);
    glm::vec3 getNormalizedViewVector() const;

    glm::vec3 _position, _viewPoint, _upVector;

    glm::dvec2 _windowCenterPosition;

    float _moveSpeed, _mouseSensitivity;
    int _forwardKeyCode, _backwardKeyCode, _leftKeyCode, _rightKeyCode;
};
