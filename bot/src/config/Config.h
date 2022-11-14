#ifndef CONFIG
#define CONFIG

#include "../util/String.h"
#include <string>

namespace config {
class Config {
   public:
    explicit Config(const std::string& file_path) : file_path_(file_path){};

    virtual std::string DebugMsg() {
        return util::string::FormatString("");
    }

   protected:
    std::string file_path_;
};

}  // namespace config

#endif
