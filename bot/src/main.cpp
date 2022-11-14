#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include <iostream>
#include "config/Worker.h"

using namespace std;

int main(int argc, char *argv[]) {
	auto worker_config = config::Worker("config/config.yaml");
    
    cout << worker_config.DebugMsg() << endl;

}

