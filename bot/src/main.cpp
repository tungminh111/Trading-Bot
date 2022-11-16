#include <iostream>
#include <memory>

#include "config/Worker.h"
#include "worker/Worker.h"

using namespace std;

int main(int argc, char *argv[]) {
    auto worker_config = make_shared<config::Worker>("config/config.yaml");

    std::cout << worker_config->DebugMsg() << std::endl;

    auto worker = worker::Worker(worker_config);
}

