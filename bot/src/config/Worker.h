#ifndef WORKER_CONFIG
#define WORKER_CONFIG

#include "Config.h"
#include "yaml-cpp/node/parse.h"
#include "yaml-cpp/yaml.h"

class WorkerConfig : protected LocalConfig {
       public:
	explicit WorkerConfig(std::string file_path) : LocalConfig(file_path) {}
	void load() {
		auto config = YAML::LoadFile(file_path_);

		enable_calling_api = config["enable_calling_api"]
					 .as<decltype(enable_calling_api)>();
	}

	bool is_enable_calling_api() { return enable_calling_api; }

       private:
	bool enable_calling_api;
};

#endif
