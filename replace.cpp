#include "replace.h"
#include <string>
#include <iostream>
using namespace std;

Replace::Replace(string in, string key)
{
	this->range = range;
	this->expression = in;
	this->key = key;
};


string Replace::encrypt()
{
	for (int i = 0; i < this->expression.size(); i++)
	{
		for (int j = 0; j < this->english_abc.size(); j++)
		{
			if (this->expression[i] == this->english_abc[j])
			{
				this->expression[i] = this->key[j];
				break;
			}
			// Capital letters
			else if ((this->expression[i] - 32) == this->english_abc[j])
			{
				this->expression[i] = this->key[j] + 32;
			}
		}
	}
	return this->expression;

};

string Replace::decrypt()
{
	for (int i = 0; i < this->expression.size(); i++)
	{
		for (int j = 0; j < this->english_abc.size(); j++)
		{
			if (this->expression[i] == this->key[j])
			{
				this->expression[i] = this->english_abc[j];
				break;
			}
			// Capital letters
			else if ((this->expression[i] - 32) == this->key[j])
			{
				this->expression[i] = this->english_abc[j] + 32;
				break;
			}
		}
	}
	return this->expression;

};