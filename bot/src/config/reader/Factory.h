#ifndef DATA_READER_CONFIG_FACTORY
#define DATA_READER_CONFIG_FACTORY

#include <memory>
#include <variant>

#include "FileReader.h"
#include "Reader.h"
#include "Type.h"
#include "yaml-cpp/node/node.h"
namespace config {
Reader LoadReaderConfig(YAML::Node config) {
    auto data_reader_type = config["type"].as<ReaderType>();
    switch (data_reader_type) {
        case ReaderType::FILE_READER:
            return FileReader(config);
        default:
            return Reader(config);
    }
}
}  // namespace Config

#endif
