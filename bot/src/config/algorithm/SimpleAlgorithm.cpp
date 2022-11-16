#include "SimpleAlgorithm.h"
#include "config/algorithm/Algorithm.h"

namespace config{
    SimpleAlgorithm::SimpleAlgorithm(YAML::Node config): Algorithm(config){
        observe_sticks =
            config["observe_sticks"].as<decltype(observe_sticks)>();
    }

}
