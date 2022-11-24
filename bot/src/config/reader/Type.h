#ifndef DATA_READER_CONFIG_TYPE
#define DATA_READER_CONFIG_TYPE
#include "yaml-cpp/node/node.h"

namespace config {
enum class ReaderType {
    BASE_READER,
    FILE_READER,
};

};  // namespace config

namespace YAML {
template <>
struct convert<config::ReaderType> {
    static Node encode(const config::ReaderType& rhs) {
        Node node;
        node.push_back((int)rhs);
        return node;
    }

    static bool decode(const Node& node, config::ReaderType& rhs) {
        rhs = static_cast<config::ReaderType>(node.as<int>());
        return true;
    }
};
}  // namespace YAML

#endif
