#ifndef ALGORITHM
#define ALGORITHM

#include "../entity/BalanceInfo.h"
#include "../entity/Kline.h"
#include "Status.h"
#include "config/algorithm/Algorithm.h"
#include "entity/Action.h"
#include <memory>

namespace algorithm {
class Algorithm {
public:
  explicit Algorithm();
  explicit Algorithm(const std::shared_ptr<config::Algorithm> &cfg);
  virtual OrderData take_action(BalanceInfo balance_info, Kline data){};

private:
  Status status_;
};
} // namespace algorithm

#endif
