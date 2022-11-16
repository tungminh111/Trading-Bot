#ifndef STRING_UTIL
#define STRING_UTIL

#include <string>
namespace util::string {
std::string FormatString(int max_buffer, const char* format, ...);
std::string FormatString(const char* format, ...);
}  // namespace util::string

#endif
