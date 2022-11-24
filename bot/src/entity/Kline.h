#ifndef KLINE
#define KLINE

#include <time.h>

#include <string>

#include "util/String.h"

struct Kline {
    time_t open_tm;
    double open_price;
    double high_price;
    double low_price;
    double close_price;
    double volumn;
    time_t close_tm;
    int64_t trade_qty;

    std::string DebugMsg() {
        return util::string::FormatString(
            "open_tm: %lld, "
            "open_price: %f, "
            "high_price: %f, "
            "low_price: %f, "
            "close_price: %f, "
            "volumn: %f, "
            "close_tm: %lld, "
            "trade_qty: %lld.",
            open_tm, open_price, high_price, low_price, close_price, volumn,
            close_tm, trade_qty);
    }
};

#endif
