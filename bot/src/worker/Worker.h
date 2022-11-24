#ifndef WORKER
#define WORKER

#include <memory>

#include "account/Account.h"
#include "algorithm/Algorithm.h"
#include "config/Worker.h"
#include "maker/Maker.h"
#include "reader/Reader.h"

namespace worker {
class Worker {
   public:
    explicit Worker(const std::shared_ptr<config::Worker>& config);
    void run();

   private:
    std::unique_ptr<reader::Reader> reader_;
    std::unique_ptr<Account> account_;
    std::unique_ptr<Maker> maker_;
    std::unique_ptr<Algorithm> algorithm_;
};
}  // namespace worker

#endif
