#ifndef FILE_READER_CONFIG
#define FILE_READER_CONFIG

#include <time.h>

#include <string>

#include "Reader.h"
#include "Type.h"
#include "util/String.h"
#include "yaml-cpp/node/node.h"
namespace config {
class FileReader : public Reader {
   public:
    using super = Reader;
    ReaderType reader_type() const override { return ReaderType::FILE_READER; }

    explicit FileReader(YAML::Node config);

    std::string DebugMsg() override {
        return util::string::FormatString("%s, file_path: %s, cur_time: %lld",
                                          super::DebugMsg().c_str(),
                                          file_path.c_str(), cur_time);
    }

    std::string file_path;
    time_t cur_time;
};
};  // namespace config
#endif
