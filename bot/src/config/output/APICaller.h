#ifndef API_CALLER_CONFIG
#define API_CALLER_CONFIG

#include <string>

#include "yaml-cpp/node/node.h"
namespace config {
class APICaller {
   public:
    APICaller() {}
    explicit APICaller(YAML::Node config) {}

    std::string DebugMsg() { return ""; }
};
}  // namespace config

#endif
