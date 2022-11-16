#ifndef READER_FACTORY
#define READER_FACTORY

#include <memory>

#include "../config/reader/FileReader.h"
#include "../config/reader/Reader.h"
#include "../config/reader/Type.h"
#include "FileReader.h"
#include "Reader.h"
namespace reader {
std::unique_ptr<Reader> create_reader(
    const std::shared_ptr<config::Reader>& config) {
    switch (config->reader_type()) {
        case config::ReaderType::FILE_READER:
            return std::make_unique<FileReader>(
                std::static_pointer_cast<config::FileReader>(config));
        default:
        case config::ReaderType::BASE_READER:
            return std::make_unique<Reader>(config);
    }
}
}  // namespace reader

#endif
