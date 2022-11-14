#ifndef ALGORITHM_CONFIG_TYPE
#define ALGORITHM_CONFIG_TYPE
#include "yaml-cpp/node/node.h"
namespace config {
enum class AlgoType { BASE_ALGO, SIMPLE_ALGO };
};

namespace YAML {
template <>
struct convert<config::AlgoType> {
    static Node encode(const config::AlgoType& rhs) {
        Node node;
        node.push_back((int)rhs);
        return node;
    }

    static bool decode(const Node& node, config::AlgoType& rhs) {
        rhs = static_cast<config::AlgoType>(node.as<int>());
        return true;
    }
};
}  // namespace YAML
#endif
