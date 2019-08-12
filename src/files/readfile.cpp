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
        buffer = (char*)malloc(sizeof(char) * (length + 1));
        if (buffer) {
            fread(buffer, sizeof(char) * length, 1, file);
        }
        fclose(file);
    }
    buffer[length] = '\0';
    return buffer;
}
