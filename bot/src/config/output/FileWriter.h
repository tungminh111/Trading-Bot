#ifndef FILE_WRITER_CONFIG
#define FILE_WRITER_CONFIG

#include "yaml-cpp/node/node.h"
namespace config {
class FileWriter {
   public:
    FileWriter() {}
    explicit FileWriter(YAML::Node config) {}

    std::string DebugMsg() { return ""; }
};
}  // namespace Config

#endif
