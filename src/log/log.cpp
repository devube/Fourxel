#include "log.hpp"
//TODO: Some better output stream (in-game console or something)
#include <stdio.h>

void _log::info(const char info[]) {
    printf("Info: %s\n", info);
}

void _log::warning(const char warning[]) {
    printf("Warning! %s\n", warning);
}

void _log::error(const char error[]) {
    printf("ERROR! %s\n", error);
}
