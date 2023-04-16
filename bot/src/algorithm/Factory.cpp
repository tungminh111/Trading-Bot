#include "Factory.h"

#include "SimpleAlgorithm.h"
#include "config/algorithm/SimpleAlgorithm.h"
#include "config/algorithm/Type.h"
#include "entity/Kline.h"

namespace algorithm {
std::unique_ptr<Algorithm>
create_algorithm(const std::shared_ptr<config::Algorithm> &config) {
  switch (config->algo_type()) {
  case config::AlgoType::SIMPLE_ALGO:
    return std::make_unique<SimpleAlgorithm>(
        std::static_pointer_cast<config::SimpleAlgorithm>(
            config)); // TODO: hard code type
  default:
    return std::make_unique<Algorithm>(config);
  }
}

} // namespace algorithm
