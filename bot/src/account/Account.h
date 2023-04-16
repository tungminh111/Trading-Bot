#ifndef ACCOUNT
#define ACCOUNT

#include "config/account/Account.h"
#include "entity/BalanceInfo.h"
#include <memory>
#include <string>

namespace account {
class Account {
public:
  explicit Account(const std::shared_ptr<config::Account> &config);
  BalanceInfo get_balance_info();

private:
  std::shared_ptr<config::Account> config_;
  std::string access_token_;
};
} // namespace account

#endif
