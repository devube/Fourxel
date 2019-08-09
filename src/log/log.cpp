#include "log.hpp"
//TODO: Some better output stream (in-game console or something)
#include <stdio.h>

void log::info(const char[] info) const {
    printf("Info: %s\n", info);
}

void log::warning(const char[] warning) const {
    printf("Warning! %s\n", warning);
}

void log::error(const char[] error) const {
    printf("ERROR! %s\n", error);
}
