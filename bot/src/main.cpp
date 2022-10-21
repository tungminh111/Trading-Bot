#include <iostream>
#include "config/Worker.h"

using namespace std;

int main(int argc, char *argv[]) {
	auto worker_config = WorkerConfig("config/config.yaml");
	worker_config.load();

	cout << worker_config.is_enable_calling_api() << endl;

	return 0;

}
