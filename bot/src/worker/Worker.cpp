#include <memory>

#include "algorithm/Action.h"
#include "config/Worker.h"
#include "entity/Kline.h"
#include "reader/Factory.h"
#include "Worker.h"

namespace worker {
Worker::Worker(const std::shared_ptr<config::Worker>& config) {
    this->reader_ = reader::create_reader(config->reader);
}

void Worker::run() {
    while (true) {
        // auto data = this->reader_->next_kline();
        // auto action_data = this->algorithm_->take_action(data);
        // this->maker_->take_action(action_data);
    }
}

}  // namespace worker
