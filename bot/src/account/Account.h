#ifndef ACCOUNT
#define ACCOUNT

#include <string>

class Account {
       public:
	virtual void init_connection() = 0;
	std::string get_access_token() { return access_token_; }

       private:
	std::string access_token_;
};

#endif
