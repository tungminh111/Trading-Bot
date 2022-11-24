#ifndef READER_BINANCE_SCHEMA
#define READER_BINANCE_SCHEMA

#include <time.h>

#include <string>

#include "Schema.h"

namespace reader::schema {
class Binance : public Schema {
   public:
    Binance();
    Kline ToKline(std::string raw_input) override;
};
}  // namespace reader::schema

#endif
