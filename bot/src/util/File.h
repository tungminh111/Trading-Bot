#ifndef FILE_UTIL
#define FILE_UTIL

#include <time.h>

#include <filesystem>
#include <string>
namespace util::file {
time_t ExtractTimestamp(const std::filesystem::directory_entry& entry);
std::string ConstructPath(const std::string& prefix, const time_t& timestamp);
}  // namespace util::file

#endif
