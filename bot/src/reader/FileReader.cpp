#include "FileReader.h"

#include <assert.h>

#include "reader/schema/Binance.h"
#include "util/File.h"
namespace reader {
const time_t kEndTime = -1;

FileReader::FileReader(const std::shared_ptr<config::FileReader>& config)
    : Reader(config), config_(config) {
    this->schema_ =
        std::make_unique<schema::Binance>();  // todo: create schema factory

    for (const auto& entry :
         std::filesystem::directory_iterator(config->file_path)) {
        this->file_map_.emplace(util::file::ExtractTimestamp(entry),
                                entry.path());
    }

    this->initFile();
}

void FileReader::initFile() {
    if (this->file_map_.empty()) {
        this->config_->cur_time = kEndTime;
        return;
    }

    auto cur_entry = this->file_map_.upper_bound(this->config_->cur_time + 1);
    if (cur_entry != this->file_map_.begin()) --cur_entry;
    this->openFile(cur_entry->second);

    bool found = false;
    std::string content;
    while (!found && getline(this->cur_fstream_, content)) {
        this->next_content = this->schema_->ToKline(content);
        if (this->next_content.open_tm > this->config_->cur_time) {
            found = true;
            break;
        }
    }

    assert(found);
}

void FileReader::nextFile() {
    auto next_entry = this->file_map_.upper_bound(this->config_->cur_time);
    if (next_entry == this->file_map_.end()) {
        this->config_->cur_time = kEndTime;
        return;
    }

    this->config_->cur_time = next_entry->first;
    this->closeFile();
    this->openFile(next_entry->second);
}

void FileReader::prepareNextContext() {
    std::string content;
    if (std::getline(this->cur_fstream_, content)) {
        this->next_content = this->schema_->ToKline(content);
        return;
    }

    this->nextFile();
    if (this->HasFinishedAllFiles()) return;

    std::getline(this->cur_fstream_, content);
    this->next_content = this->schema_->ToKline(content);
}

Kline FileReader::NextKline() {
    assert(!this->HasFinishedAllFiles());

    Kline ret = this->next_content;
    this->config_->cur_time = ret.open_tm;

    prepareNextContext();
    return ret;
}

void FileReader::openFile(const std::string& path) {
    std::cout << "Open file: " << path << std::endl;
    this->cur_fstream_ = std::fstream(path, std::fstream::in);
    assert(this->cur_fstream_.is_open());
}

bool FileReader::HasFinishedAllFiles() {
    return this->config_->cur_time == kEndTime;
}

FileReader::~FileReader() {
    this->closeFile();
}

void FileReader::closeFile() {
    if (this->cur_fstream_.is_open())
        this->cur_fstream_.close();
}

}  // namespace reader

