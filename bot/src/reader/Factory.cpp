#include "Factory.h"

#include "FileReader.h"
#include "config/reader/FileReader.h"
#include "config/reader/Type.h"
#include "entity/Kline.h"

namespace reader {
std::unique_ptr<Reader> create_reader(
    const std::shared_ptr<config::Reader> &config) {
    switch (config->reader_type()) {
        case config::ReaderType::FILE_READER:
            return std::make_unique<FileReader>(
                std::static_pointer_cast<config::FileReader>(
                    config));  // TODO: hard code type
        default:
            return std::make_unique<Reader>(config);
    }
}

}  // namespace reader
