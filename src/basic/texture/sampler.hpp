#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum MagnificationFilter {
    MAG_FILTER_NEAREST,
    MAG_FILTER_BILINEAR
};

enum MinificationFilter {
    MIN_FILTER_NEAREST,
    MIN_FILTER_BILINEAR,
    MIN_FILTER_NEAREST_MIPMAP,
    MIN_FILTER_BILINEAR_MIPMAP,
    MIN_FILTER_TRILINEAR
};

class Sampler {
public:
    void create();
    void bind(int textureUnit = 0) const;
    void deleteSampler();

    void setMagnificationFilter(const MagnificationFilter magnificationFiler) const;
    void setMinificationFilter(const MinificationFilter minificationFilter) const;
    void setRepeat(bool repeat) const;

private:
    GLuint _samplerID = 0;
    bool _isCreated = false;

    bool createdCheck() const;
};
