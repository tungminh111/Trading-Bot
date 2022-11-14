#ifndef ALGORITHM_CONFIG_FACTORY
#define ALGORITHM_CONFIG_FACTORY

#include <memory>
#include <string>
#include <variant>

#include "Algorithm.h"
#include "SimpleAlgorithm.h"
#include "Type.h"
#include "yaml-cpp/node/node.h"
namespace config {
Algorithm LoadAlgorithmConfig(YAML::Node config) {
    AlgoType algo_name = config["type"].as<AlgoType>();
    switch (algo_name) {
        case AlgoType::SIMPLE_ALGO:
            return SimpleAlgorithm(config);
        default:
            return Algorithm(config);
    }
}
};  // namespace Config::Local

#endif
