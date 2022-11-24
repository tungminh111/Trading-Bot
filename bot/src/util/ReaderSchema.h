#ifndef READER_SCHEMA_UTIL
#define READER_SCHEMA_UTIL

#include <sstream>
namespace util::readerschema {
    template<typename T>
    T GetNextItem(std::stringstream& row);
}

#endif
