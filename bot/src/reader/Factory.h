#ifndef READER_FACTORY
#define READER_FACTORY

#include <memory>

#include "Reader.h"
#include "config/reader/Reader.h"
namespace reader {
std::unique_ptr<Reader> create_reader(
    const std::shared_ptr<config::Reader>& config);
}  // namespace reader

#endif
