#ifndef ALGORITHM
#define ALGORITHM

#include "../entity/Kline.h"
#include "Action.h"
#include "Status.h"

class Algorithm {
       public:
	virtual ActionData take_action(Kline data) = 0;

       private:
	Status status_;
};

#endif

