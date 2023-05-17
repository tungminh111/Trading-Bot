#ifndef MAKER
#define MAKER

#include "algorithm/Action.h"
#include "APIWriter.h"
#include "Logger.h"

class Maker {
       public:
	Maker(Logger* logger, APIWriter* writer)
	    : logger_(logger), api_writer_(writer) {}
	void take_action(OrderData data);

       private:
	Logger* logger_;
	APIWriter* api_writer_;
};

#endif
