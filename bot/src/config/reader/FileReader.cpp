#include "FileReader.h"

namespace config {
FileReader::FileReader(YAML::Node config) : Reader(config) {
    file_path = config["file_path"].as<decltype(file_path)>();
    cur_time = config["cur_time"].as<decltype(cur_time)>();
}
}  // namespace config
