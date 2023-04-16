#ifndef ACCOUNT_CONFIG_TYPE
#define ACCOUNT_CONFIG_TYPE
#include "yaml-cpp/node/node.h"

namespace config {
enum class AccountType {
    LOCAL,
    REMOTE,
};

};  // namespace config

namespace YAML {
template <>
struct convert<config::AccountType> {
    static Node encode(const config::AccountType &rhs) {
        Node node;
        node.push_back((int)rhs);
        return node;
    }

    static bool decode(const Node &node, config::AccountType &rhs) {
        rhs = static_cast<config::AccountType>(node.as<int>());
        return true;
    }
};
}  // namespace YAML

#endif
