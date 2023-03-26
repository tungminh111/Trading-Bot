
#include "Binance.h"

#include <sstream>

#include "util/ReaderSchema.h"
namespace reader::schema {

Binance::Binance() {}

Kline Binance::ToData(std::string raw_input) {
    std::stringstream ss(raw_input);
    time_t open_tm = util::readerschema::GetNextItem<time_t>(ss);
    double open_price = util::readerschema::GetNextItem<double>(ss);
    double high_price = util::readerschema::GetNextItem<double>(ss);
    double low_price = util::readerschema::GetNextItem<double>(ss);
    double close_price = util::readerschema::GetNextItem<double>(ss);
    double volumn = util::readerschema::GetNextItem<double>(ss);
    time_t close_tm = util::readerschema::GetNextItem<time_t>(ss);
    double asset_volumn = util::readerschema::GetNextItem<double>(ss);
    int64_t trade_qty = util::readerschema::GetNextItem<int64_t>(ss);

    Kline ret;
    ret.open_tm = open_tm;
    ret.close_tm = close_tm;
    ret.open_price = open_price;
    ret.close_price = close_price;
    ret.high_price = high_price;
    ret.low_price = low_price;
    ret.volumn = volumn;
    ret.trade_qty = trade_qty;
    return ret;
}
}  // namespace reader::schema
