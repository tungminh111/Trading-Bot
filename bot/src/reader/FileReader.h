#ifndef FILEREADER
#define FILEREADER

#include <ctime>
#include <filesystem>
#include <iostream>
#include <memory>
#include <vector>

#include "../config/reader/FileReader.h"
#include "Reader.h"

namespace reader {
class FileReader : public Reader {
   public:
    explicit FileReader(const std::shared_ptr<config::FileReader>& config)
        : Reader(config) {
        for (const auto& entry :
             std::filesystem::directory_iterator(config->file_path))
            std::cout << entry.path() << std::endl;
    }

   private:
    std::shared_ptr<config::FileReader> config;
};
}  // namespace reader

#endif
