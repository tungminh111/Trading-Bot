#ifndef CONFIG
#define CONFIG

#include <string>

class LocalConfig {
public:
	explicit LocalConfig(std::string file_path): file_path_(file_path) {};
	virtual void load() = 0;
protected: 
	std::string file_path_;

};

#endif
