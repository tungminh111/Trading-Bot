#ifndef SIMPLE_ALGORITHM_CONFIG
#define SIMPLE_ALGORITHM_CONFIG

#include <string>

#include "Algorithm.h"
#include "Type.h"
#include "util/String.h"
#include "yaml-cpp/node/node.h"

namespace config {
class SimpleAlgorithm : public Algorithm {
   public:
    using super = Algorithm;
    AlgoType algo_type() const override { return AlgoType::SIMPLE_ALGO; }

    explicit SimpleAlgorithm(YAML::Node config);

    std::string DebugMsg() override {
        return util::string::FormatString("{%s, observe_sticks: %d}",
                                          super::DebugMsg().c_str(),
                                          observe_sticks);
    }

    int observe_sticks;
};
};  // namespace config

#endif
