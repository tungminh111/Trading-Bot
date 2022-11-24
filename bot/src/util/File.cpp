#include "File.h"

#include <algorithm>

namespace util::file {
/*
 * file with format path/XX.csv
 * return XX (long)
 */
time_t ExtractTimestamp(const std::filesystem::directory_entry& entry) {
    std::string path = entry.path();
    std::reverse(path.begin(), path.end());
    path = path.substr(0, path.find('/'));
    path = path.substr(path.find('.') + 1);
    std::reverse(path.begin(), path.end());
    return std::stoll(path);
}

std::string ConstructPath(const std::string& prefix, const time_t& timestamp) {
    return prefix + "/" + std::to_string(timestamp) + ".csv";
}

}  // namespace util::file
