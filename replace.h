#pragma once
#include <iostream>
#include <string>

class Replace
{
private:
	std::string expression;
	int range;
	std::string key;
	std::string english_abc = "abcdefghijklmnopqrstuvwxyz";

public:
	Replace(std::string in, std::string key);
	std::string encrypt();
	std::string decrypt();
};
