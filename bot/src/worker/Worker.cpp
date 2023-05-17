#include "config/Worker.h"

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <ratio>
#include <thread>

#include "Worker.h"
#include "algorithm/Action.h"
#include "algorithm/Factory.h"
#include "entity/Kline.h"
#include "reader/Factory.h"
#include <unistd.h>

namespace worker {
Worker::Worker(const std::shared_ptr<config::Worker> &config) {
  this->reader_ = reader::create_reader(config->reader);
  this->account_ = std::make_unique<account::Account>(config->account);
  this->algorithm_ = algorithm::create_algorithm(config->algorithm);
}

void Worker::run() {
  using namespace std::chrono;
  Kline kline;

  auto interval = milliseconds(this->reader_->getInterval() * 1000);

  while (true) {
    auto start_tm = system_clock::now();

    kline = this->reader_->NextKline(
        duration_cast<seconds>(start_tm.time_since_epoch()).count());

    std::cout << "Kline: " << kline.DebugMsg() << std::endl;

    auto end_tm = system_clock::now();
    auto elapse = duration_cast<milliseconds>(end_tm - start_tm);
    if (elapse < interval) {
      auto sleep_tm = interval - elapse;
      std::cout << "elapse: " << elapse.count()
                << ", sleep: " << sleep_tm.count() << std::endl;
      std::this_thread::sleep_for(sleep_tm);
    }
  }
}

} // namespace worker
