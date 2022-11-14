#include "String.h"

#include <cstdarg>
#include <cstdio>
#include <iostream>

namespace util::string {
std::string FormatString(int max_buffer, const char* format, ...) {
    va_list vl;
    va_start(vl, format);
    char buffer[max_buffer];

    vsnprintf(buffer, max_buffer, format, vl);

    return buffer;
}

const int kDefaultMaxBuffer = 300;

std::string FormatString(const char* format, ...) {
    va_list vl;
    va_start(vl, format);

    char buffer[kDefaultMaxBuffer];

    vsnprintf(buffer, kDefaultMaxBuffer, format, vl);
    return buffer;
}

}  // namespace util::string
