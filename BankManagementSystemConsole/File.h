#pragma once
#include <string>
static const struct File
{
private:
	std::string account = "account.dat";
	std::string temporary = "Temp.dat";
public:
	std::string get_account_filename();
	std::string get_temporary_filename();
};