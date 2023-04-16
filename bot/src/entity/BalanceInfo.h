#ifndef BALANCE_INFO
#define BALANCE_INFO

#include "util/String.h"
#include "yaml-cpp/node/node.h"
#include <string>
#include <vector>

struct SingleAssetInfo {
  std::string type;
  float balance;

  std::string DebugMsg() const {
    return util::string::FormatString("{\"type\":\"%s\", \"balance\": %g}",
                                      type.c_str(), balance);
  }
};

struct BalanceInfo {
  std::vector<SingleAssetInfo> asset_infos;

  std::string DebugMsg() {
    std::vector<std::string> asset_debug_msgs;
    asset_debug_msgs.reserve(asset_infos.size());
    for (const SingleAssetInfo &ai : asset_infos) {
      asset_debug_msgs.push_back(ai.DebugMsg());
    }

    return util::string::FormatString(
        "{\"asset_infos\": \"%s\"}",
        util::string::Join(asset_debug_msgs, ",").c_str());
  }
};

namespace YAML {
template <> struct convert<SingleAssetInfo> {
  static Node encode(const SingleAssetInfo &rhs) {
    Node node;
    node["type"].push_back(rhs.type);
    node["balance"].push_back(rhs.balance);
    return node;
  }

  static bool decode(const Node &node, SingleAssetInfo &rhs) {
    rhs.type = node["type"].as<std::string>();
    rhs.balance = node["balance"].as<float>();
    return true;
  }
};

template <> struct convert<BalanceInfo> {
  static Node encode(const BalanceInfo &rhs) {
    Node node;
    node["asset_infos"].push_back(rhs.asset_infos);
    return node;
  }

  static bool decode(const Node &node, BalanceInfo &rhs) {
    rhs.asset_infos = node["asset_infos"].as<std::vector<SingleAssetInfo>>();
    return true;
  }
};

} // namespace YAML

#endif // !ACCOUNT_INFO
