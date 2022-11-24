#ifndef FILEREADER
#define FILEREADER

#include <time.h>

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "Reader.h"
#include "config/reader/FileReader.h"
#include "reader/schema/Schema.h"

namespace reader {
class FileReader : public Reader {
   public:
    explicit FileReader(const std::shared_ptr<config::FileReader>& config);

    bool HasFinishedAllFiles();

    Kline NextKline() override;

   private:
    void initFile();
    void nextFile();
    void openFile(const std::string& path);
    void closeFile();
    void prepareNextContext();
    ~FileReader();

    // for checking if still have data ahead
    Kline next_content;
    std::fstream cur_fstream_;
    std::shared_ptr<config::FileReader> config_;
    std::map<time_t, std::string> file_map_;
    std::unique_ptr<schema::Schema> schema_;
};
}  // namespace reader

#endif
