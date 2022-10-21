#ifndef KLINE
#define KLINE

#include <time.h>

struct Kline {
	time_t open_tm;
	float open_price;
	float high_price;
	float low_price;
	float close_price;
	float volumn;
	time_t close_tm;
	int trade_quantity;
};

#endif
