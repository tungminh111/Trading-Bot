#ifndef ALGORITHM_CONFIG
#define ALGORITHM_CONFIG

#include <string>

#include "util/String.h"
#include "Type.h"
#include "yaml-cpp/yaml.h"

namespace config {
class Algorithm {
   public:
    virtual AlgoType algo_type() const { return AlgoType::BASE_ALGO; };

    virtual std::string DebugMsg() {
        return util::string::FormatString("{algo_type: %d}", this->algo_type());
    }

    Algorithm() {}

    explicit Algorithm(YAML::Node config);
};
};  // namespace config

#endif
