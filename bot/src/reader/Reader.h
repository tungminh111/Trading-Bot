#ifndef READER
#define READER

#include <memory>

#include "config/reader/Reader.h"
#include "entity/Kline.h"
namespace reader {
class Reader {
   public:
    explicit Reader(const std::shared_ptr<config::Reader>& config)
        : config(config) {}
    virtual Kline NextKline() {};
    // virtual void CurrentOrderBook() = 0;
   private:
    std::shared_ptr<config::Reader> config;
};
}  // namespace reader

#endif
