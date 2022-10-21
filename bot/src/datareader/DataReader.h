#ifndef DATAREADER
#define DATAREADER

#include "../entity/Kline.h"

class DataReader {
       public:
	explicit DataReader(int interval) : kline_interval(interval) {}
	virtual Kline next_kline() = 0;
	// virtual void CurrentOrderBook() = 0;
       protected:
	int kline_interval;
};

#endif
