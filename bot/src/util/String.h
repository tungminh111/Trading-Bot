#ifndef STRING_UTIL
#define STRING_UTIL

#include <string>
namespace util::string {
std::string FormatString(int max_buffer, const char *format, ...);
std::string FormatString(const char *format, ...);

std::string Join(const std::vector<std::string> &strs,
                 const std::string &delim);
} // namespace util::string

#endif
