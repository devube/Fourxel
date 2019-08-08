#include "walkingCamera.hpp"

#include "basic/input.hpp"
#include "basic/time/timeUtils.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

WalkingCamera::WalkingCamera(const glm::vec3& position, const glm::vec3& viewPoint,
const glm::vec3& upVector, float moveSpeed, float mouseSensitivity)
    : _position(position), _viewPoint(viewPoint), _upVector(upVector),
    _moveSpeed(moveSpeed), _mouseSensitivity(mouseSensitivity) {}

void WalkingCamera::setWindowCenterPosition(glm::dvec2 windowCenterPosition) {
    _windowCenterPosition = windowCenterPosition;
}

void WalkingCamera::setMoveSpeed(float moveSpeed) {
    _moveSpeed = moveSpeed;
}

void WalkingCamera::setMouseSensitivity(float sensitivity) {
    _mouseSensitivity = sensitivity;
}

void WalkingCamera::setControls(int forwardKeyCode, int backwardKeyCode,
    int leftKeyCode, int rightKeyCode) {
    _forwardKeyCode = forwardKeyCode;
    _backwardKeyCode = backwardKeyCode;
    _leftKeyCode = leftKeyCode;
    _rightKeyCode = rightKeyCode;
}

glm::mat4 WalkingCamera::getViewMatrix() const {
    return glm::lookAt(_position, _viewPoint, _upVector);
}

void WalkingCamera::update() {
    if (keyPressed(_forwardKeyCode)) {
        moveBy(timeUtils::sof(_moveSpeed));
    } else if (keyPressed(_backwardKeyCode)) {
        moveBy(-timeUtils::sof(_moveSpeed));
    }

    if (keyPressed(_rightKeyCode)) {
        strafeBy(timeUtils::sof(_moveSpeed));
    } else if (keyPressed(_leftKeyCode)) {
        strafeBy(-timeUtils::sof(_moveSpeed));
    }

    glm::dvec2 cursorPosition = getCursorPosition();
    glm::dvec2 delta = _windowCenterPosition - cursorPosition;

    if (delta.x != 0) {
        rotateHorizontally(float(delta.x) * _mouseSensitivity);
    }

    if (delta.y != 0) {
        rotateVertically(float(delta.y) * _mouseSensitivity);
    }

    setCursorPosition(_windowCenterPosition.x, _windowCenterPosition.y);
}



void WalkingCamera::moveBy(float distance) {
    glm::vec3 vOffset = getNormalizedViewVector();
    vOffset *= distance;
    _position += vOffset;
    _viewPoint += vOffset;
}

void WalkingCamera::strafeBy(float distance) {
    glm::vec3 strafeVector = glm::normalize(glm::cross(getNormalizedViewVector(), _upVector));
    strafeVector *= distance;

    _position += strafeVector;
    _viewPoint += strafeVector;
}

void WalkingCamera::rotateHorizontally(float angleInDegrees) {
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f),
        glm::radians(angleInDegrees), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::vec4 rotatedViewVector = rotationMatrix * glm::vec4(getNormalizedViewVector(), 0.0f);
    _viewPoint = _position + glm::vec3(rotatedViewVector.x, rotatedViewVector.y,
                                        rotatedViewVector.z);
}

void WalkingCamera::rotateVertically(float angleInDegrees) {
    glm::vec3 viewVector = getNormalizedViewVector();
    glm::vec3 viewVectorNoY = glm::normalize(glm::vec3(viewVector.x, 0.0f, viewVector.z));

    float currentAngleDegrees = glm::degrees(acos(glm::dot(viewVectorNoY, viewVector)));
    if (viewVector.y < 0.0f) {
        currentAngleDegrees = -currentAngleDegrees;
    }

    float newAngleDegrees = currentAngleDegrees + angleInDegrees;
    if (newAngleDegrees > -85.0f && newAngleDegrees < 85.0f) {
        glm::vec3 rotationAxis = glm::cross(getNormalizedViewVector(), _upVector);
        rotationAxis = glm::normalize(rotationAxis);

        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angleInDegrees), rotationAxis);
        glm::vec4 rotatedViewVector = rotationMatrix * glm::vec4(getNormalizedViewVector(), 0.0f);

        _viewPoint = _position + glm::vec3(rotatedViewVector);
    }
}

glm::vec3 WalkingCamera::getNormalizedViewVector() const {
    return glm::normalize(_viewPoint - _position);
}
