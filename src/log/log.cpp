#include "log.hpp"
//TODO: Some better output stream (in-game console or something)
#include <stdio.h>

void _log::info(const char info[], const char *file, int line) {
    printf("Info: %s\n\tFile: %s(%i)\n", info, file, line);
}

void _log::warning(const char warning[], const char *file, int line) {
    printf("Warning! %s\n\tFile: %s(%i)\n", warning, file, line);
}

void _log::error(const char error[], const char *file, int line) {
    printf("ERROR! %s\n\tFile: %s(%i)\n", error, file, line);
}
