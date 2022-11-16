#ifndef DATA_READER_CONFIG
#define DATA_READER_CONFIG

#include <sys/_types/_time_t.h>

#include <ctime>
#include <string>

#include "util/String.h"
#include "Type.h"
#include "yaml-cpp/yaml.h"
namespace config {
class Reader {
   public:
    virtual ReaderType reader_type() const { return ReaderType::BASE_READER; };

    Reader(){};

    explicit Reader(YAML::Node config);

    virtual std::string DebugMsg() {
        return util::string::FormatString("reader_type: %d, kline_interval: %d",
                                          reader_type(), kline_interval);
    }

    std::time_t kline_interval;
};
};  // namespace config
#endif
