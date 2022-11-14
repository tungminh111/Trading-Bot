#ifndef FILE_READER_CONFIG
#define FILE_READER_CONFIG

#include <iostream>
#include <ostream>
#include <sys/_types/_time_t.h>

#include <string>

#include "../../util/String.h"
#include "Reader.h"
#include "Type.h"
#include "yaml-cpp/node/node.h"
namespace config {
class FileReader : public Reader {
   public:
    using super = Reader;
    ReaderType reader_type() const override {
        return ReaderType::FILE_READER;
    }

    explicit FileReader(YAML::Node config) : Reader(config) {
        file_path = config["file_path"].as<decltype(file_path)>();
        cur_time = config["cur_time"].as<decltype(cur_time)>();
    }

    std::string DebugMsg() override {
        return util::string::FormatString("%s, file_path: %s, cur_time: %d",
                                          file_path.c_str(), cur_time);
    }

    std::string file_path;
    time_t cur_time;
};
};  // namespace config
#endif
