#include "Account.h"

namespace config {
Account::Account(YAML::Node config) {
  account_type = config["type"].as<AccountType>();
  username = config["username"].as<decltype(username)>();
  password = config["password"].as<decltype(password)>();
  balance_info = config["balance_info"].as<decltype(balance_info)>();
}
} // namespace config
