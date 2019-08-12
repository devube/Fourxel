/* Functions for information logging */

#pragma once

namespace _log {
    void info(const char info[], const char *file, int line);
    void warning(const char warning[], const char *file, int line);
    void error(const char error[], const char *file, int line);
} /* namespace log */
    