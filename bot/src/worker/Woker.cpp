#include "../algorithm/Action.h"
#include "../entity/Kline.h"
#include "Worker.h"

void Worker::init_resource() { this->account_->init_connection(); }

void Worker::run() {
	while (true) {
		auto data = this->reader_->next_kline();
		auto action_data = this->algorithm_->take_action(data);
		this->maker_->take_action(action_data);
	}
}
