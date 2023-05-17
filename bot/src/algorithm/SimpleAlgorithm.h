#ifndef SIMPLE_ALGORITHM
#define SIMPLE_ALGORITHM
#include "Algorithm.h"
#include "config/algorithm/SimpleAlgorithm.h"
#include <memory>

namespace algorithm {
class SimpleAlgorithm : public Algorithm {
public:
  explicit SimpleAlgorithm(const std::shared_ptr<config::SimpleAlgorithm> &cfg);
  OrderData take_action(BalanceInfo balance_info, Kline data) override;

private: 

};
} // namespace algorithm

#endif // !SIMPLE_ALGORITHM
