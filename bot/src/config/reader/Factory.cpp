#include "Factory.h"

#include <memory>

#include "Factory.h"
namespace config {
std::shared_ptr<Reader> LoadReaderConfig(YAML::Node config) {
    auto data_reader_type = config["type"].as<ReaderType>();
    switch (data_reader_type) {
        case ReaderType::FILE_READER:
            return std::make_shared<FileReader>(config);
        default:
            return std::make_shared<Reader>(config);
    }
}
}  // namespace config
