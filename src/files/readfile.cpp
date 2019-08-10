#include "readfile.hpp"
#include <stdio.h>
#include <stdlib.h>

char* strFromFile(const char* path) {
    char* buffer = 0;
    long length;
    FILE* file = fopen(path, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = (char*)malloc(length);
        if (buffer) {
            fread(buffer, 1, length, file);
        }
        fclose(file);
    }

    return buffer;
}
