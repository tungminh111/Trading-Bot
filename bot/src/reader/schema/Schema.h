#ifndef READER_SCHEMA
#define READER_SCHEMA

#include <string>

#include "entity/Kline.h"
namespace reader::schema {
class Schema {
   public:
    Schema(){};
    virtual Kline ToKline(std::string raw_input){};
};
}  // namespace reader::schema

#endif

