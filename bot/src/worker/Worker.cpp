#include "config/Worker.h"

#include <iostream>
#include <memory>

#include "Worker.h"
#include "algorithm/Action.h"
#include "entity/Kline.h"
#include "reader/Factory.h"

namespace worker {
Worker::Worker(const std::shared_ptr<config::Worker>& config) {
    this->reader_ = reader::create_reader(config->reader);
}

void Worker::run() {
    std::cout << this->reader_->NextKline().DebugMsg() << std::endl;
    std::cout << this->reader_->NextKline().DebugMsg() << std::endl;
}

}  // namespace worker
