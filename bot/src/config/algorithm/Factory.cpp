#include "Factory.h"

namespace config {
std::shared_ptr<Algorithm> LoadAlgorithmConfig(YAML::Node config) {
    AlgoType algo_name = config["type"].as<AlgoType>();
    switch (algo_name) {
        case AlgoType::SIMPLE_ALGO:
            return std::make_shared<SimpleAlgorithm>(config);
        default:
            return std::make_shared<Algorithm>(config);
    }
}
};  // namespace config

