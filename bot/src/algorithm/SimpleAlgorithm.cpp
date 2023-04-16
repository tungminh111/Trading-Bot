#include "SimpleAlgorithm.h"

namespace algorithm {
SimpleAlgorithm::SimpleAlgorithm(
    const std::shared_ptr<config::SimpleAlgorithm> &cfg)
    : Algorithm(std::static_pointer_cast<config::Algorithm>(cfg)) {}

ActionData SimpleAlgorithm::take_action(BalanceInfo balance_info, Kline data) {}
} // namespace algorithm
