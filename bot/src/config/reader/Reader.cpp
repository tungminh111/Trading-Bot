#include "Reader.h"

namespace config {
Reader::Reader(YAML::Node config) {
    kline_interval = config["kline_interval"].as<decltype(kline_interval)>();
}
}  // namespace config
