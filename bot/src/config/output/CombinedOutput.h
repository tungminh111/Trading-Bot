#ifndef COMBINED_OUTPUT_CONFIG
#define COMBINED_OUTPUT_CONFIG

#include <cstdio>
#include <memory>
#include <string>

#include "util/String.h"
#include "APICaller.h"
#include "FileWriter.h"
#include "yaml-cpp/node/node.h"
namespace config {
class CombinedOutput {
   public:
    CombinedOutput() {}

    explicit CombinedOutput(YAML::Node config)
        : file_writer(config), api_caller(config) {
        enable_calling_api =
            config["enable_calling_api"].as<decltype(enable_calling_api)>();

        file_writer = FileWriter(config["file_writer"]);

        api_caller = APICaller(config["api_caller"]);
    };

    std::string DebugMsg() {
        return util::string::FormatString(
            "{enable_calling_api: %s, FileWriter: %s, APICaller: %s}",
            enable_calling_api ? "true": "false", file_writer.DebugMsg().c_str(),
            api_caller.DebugMsg().c_str());
    }

   private:
    bool enable_calling_api;
    FileWriter file_writer;
    APICaller api_caller;
};
}  // namespace config

#endif
