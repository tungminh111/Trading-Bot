#ifndef ACCOUNT_CONFIG
#define ACCOUNT_CONFIG
#include <string>

#include "config/account/Type.h"
#include "entity/BalanceInfo.h"
#include "util/String.h"
#include "yaml-cpp/yaml.h"
namespace config {
class Account {
public:
  explicit Account(YAML::Node config);

  virtual std::string DebugMsg() {
    return util::string::FormatString(
        "{\"reader_type\": %d, \"balance_info\": \"%s\", \"username\": \"%s\", "
        "\"password\": \"%s\"}",
        account_type, balance_info.DebugMsg().c_str(), username.c_str(),
        password.c_str());
  }

  AccountType account_type;
  BalanceInfo balance_info;
  std::string username, password;
};
}; // namespace config

#endif
