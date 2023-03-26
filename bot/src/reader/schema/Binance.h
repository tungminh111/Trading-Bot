#ifndef READER_BINANCE_SCHEMA
#define READER_BINANCE_SCHEMA

#include <time.h>

#include <string>

#include "Schema.h"
#include "entity/Kline.h"

namespace reader::schema {
class Binance : public Schema {
   public:
    explicit Binance();
    Kline ToData(std::string raw_input) override;
};

}  // namespace reader::schema

#endif
