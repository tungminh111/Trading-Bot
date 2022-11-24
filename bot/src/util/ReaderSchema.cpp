#include "ReaderSchema.h"

#include <time.h>

#include <string>

namespace util::readerschema {
template <>
long long GetNextItem<long long>(std::stringstream &row) {
    std::string item;
    std::getline(row, item, ',');
    return std::stoll(item);
}

template <>
time_t GetNextItem<time_t>(std::stringstream &row) {
    return GetNextItem<long long>(row);
}

template <>
double GetNextItem<double>(std::stringstream &row) {
    std::string item;
    std::getline(row, item, ',');
    return std::stod(item);
}
}  // namespace util::readerschema
