#ifndef WORKER
#define WORKER

#include <memory>

#include "../account/Account.h"
#include "../datareader/DataReader.h"
#include "../algorithm/Algorithm.h"
#include "../maker/Maker.h"

class Worker {
       public:
	void init_resource();
	void run();

       private:
	std::unique_ptr<DataReader> reader_;
	std::unique_ptr<Account> account_;
	std::unique_ptr<Maker> maker_;
	std::unique_ptr<Algorithm> algorithm_;
	
};

#endif
