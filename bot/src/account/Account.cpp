#include "Account.h"

namespace account {
Account::Account(const std::shared_ptr<config::Account> &config)
    : config_(config) {}

BalanceInfo Account::get_balance_info() { return config_->balance_info; }
} // namespace account
