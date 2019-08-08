#include "texture.hpp"

#include <iostream>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#endif

bool Texture::loadTexture2D(const std::string& fileName, bool generateMipmaps) {
    stbi_set_flip_vertically_on_load(1);
    const auto imageData = stbi_load(fileName.c_str(), &_width, &_height, &_bytesPerPixel, 0);
    if (imageData == nullptr) {
        std::cout << "Failed to load image " << fileName << "!\n";
        return false;
    }
    glGenTextures(1, &_textureID);
    glBindTexture(GL_TEXTURE_2D, _textureID);

    GLenum internalFormat = 0;
    GLenum format = 0;
    if (_bytesPerPixel == 4) {
        internalFormat = format = GL_RGBA;
    } else if (_bytesPerPixel == 3) {
        internalFormat = format = GL_RGB;
    } else if (_bytesPerPixel == 1) {
        internalFormat = format = GL_ALPHA;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, _width, _height, 0, format, GL_UNSIGNED_BYTE, imageData);

    if (generateMipmaps) {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(imageData);
    _isLoaded = true;
    return true;
}

void Texture::bind(const int textureUnit) const {
    if (!isLoadedCheck()) {
        return;
    }

    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, _textureID);
}

void Texture::deleteTexture() {
    if (!isLoadedCheck()) {
        return;
    }

    glDeleteTextures(1, &_textureID);
    _isLoaded = false;
}

int Texture::getWidth() const {
    return _width;
}

int Texture::getHeight() const {
    return _height;
}

int Texture::getBytesPerPixel() const {
    return _bytesPerPixel;
}


bool Texture::isLoadedCheck() const {
    if (!_isLoaded) {
        std::cout << "Attempting to access non loaded texture!" << '\n';
    }

    return true;
}
