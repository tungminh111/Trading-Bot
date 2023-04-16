#ifndef ALGORITHM_FACTORY
#define ALGORITHM_FACTORY
#include <memory>

#include "Algorithm.h"
#include "config/algorithm/Algorithm.h"
namespace algorithm {
std::unique_ptr<Algorithm>
create_algorithm(const std::shared_ptr<config::Algorithm> &config);
} // namespace algorithm

#endif // !ALGORITHM_FACTORY
