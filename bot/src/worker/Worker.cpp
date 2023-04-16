#include "config/Worker.h"

#include <ctime>
#include <iostream>
#include <memory>

#include "Worker.h"
#include "algorithm/Action.h"
#include "algorithm/Factory.h"
#include "entity/Kline.h"
#include "reader/Factory.h"

namespace worker {
Worker::Worker(const std::shared_ptr<config::Worker> &config) {
  this->reader_ = reader::create_reader(config->reader);
  this->account_ = std::make_unique<account::Account>(config->account);
  this->algorithm_ = algorithm::create_algorithm(config->algorithm);
}

void Worker::run() {

  Kline kline;

  while (true) {
    int start_tm = std::time(nullptr);

    kline = this->reader_->NextKline(start_tm);

    int end_tm = std::time(nullptr);
  }
}

} // namespace worker
