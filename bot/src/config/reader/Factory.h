#ifndef READER_CONFIG_FACTORY
#define READER_CONFIG_FACTORY

#include <memory>
#include <variant>

#include "FileReader.h"
#include "Reader.h"
#include "yaml-cpp/node/node.h"
namespace config {
std::shared_ptr<Reader> LoadReaderConfig(YAML::Node config);
} // namespace config

#endif
