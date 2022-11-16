#ifndef ALGORITHM_CONFIG_FACTORY
#define ALGORITHM_CONFIG_FACTORY

#include <memory>
#include <string>
#include <variant>

#include "Algorithm.h"
#include "SimpleAlgorithm.h"
#include "Type.h"
#include "yaml-cpp/yaml.h"
namespace config {
std::shared_ptr<Algorithm> LoadAlgorithmConfig(YAML::Node config);
};  // namespace config

#endif
