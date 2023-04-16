#ifndef WORKER_CONFIG
#define WORKER_CONFIG

#include <algorithm>
#include <memory>
#include <string>
#include <variant>

#include "../util/String.h"
#include "Config.h"
#include "algorithm/Algorithm.h"
#include "algorithm/Factory.h"
#include "algorithm/SimpleAlgorithm.h"
#include "config/account/Account.h"
#include "output/CombinedOutput.h"
#include "reader/Factory.h"
#include "reader/FileReader.h"
#include "reader/Reader.h"
#include "yaml-cpp/node/parse.h"
#include "yaml-cpp/yaml.h"

namespace config {
class Worker : public Config {
public:
  explicit Worker(const std::string &file_path) : Config(file_path) {
    auto config = YAML::LoadFile(file_path_);

    algorithm = LoadAlgorithmConfig(config["algorithm"]);

    reader = LoadReaderConfig(config["reader"]);

    output = std::make_shared<CombinedOutput>(config["output"]);

    account = std::make_shared<Account>(config["account"]);
  }

  std::string DebugMsg() override {
    return util::string::FormatString(
        "{Account: %s, Reader: %s, Algorithm: %s, Output: %s}",
        account->DebugMsg().c_str(), reader->DebugMsg().c_str(),
        algorithm->DebugMsg().c_str(), output->DebugMsg().c_str());
  }

  std::shared_ptr<Account> account;
  std::shared_ptr<Reader> reader;
  std::shared_ptr<Algorithm> algorithm;
  std::shared_ptr<CombinedOutput> output;
};

} // namespace config

#endif
