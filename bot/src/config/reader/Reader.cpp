#include "Reader.h"

namespace config {
Reader::Reader(YAML::Node config) {
  interval = config["interval"].as<decltype(interval)>();
}
} // namespace config
