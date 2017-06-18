#pragma once
#include <string>

class Ceaser
{
private:
	std::string expression;
	int key;

public:
	Ceaser(std::string in, int key);
	std::string decrypt();
	std::string encrypt();
};
