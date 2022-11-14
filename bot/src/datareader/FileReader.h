#ifndef FILEREADER
#define FILEREADER

#include <ctime>
#include <filesystem>
#include <iostream>
#include <vector>

#include "../config/datareader/FileReader.h"
#include "DataReader.h"

class FileReader : protected DataReader {
       public:
	explicit FileReader(Config::FileReader config)
	    : DataReader(config.kline_interval) {
		for (const auto& entry :
		     std::filesystem::directory_iterator(config.file_path))
			std::cout << entry.path() << std::endl;
	}

       protected:
	std::time_t cur_time;
	std::vector<std::string> file_names;
};

#endif
