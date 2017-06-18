#include <iostream>
#include <string>
#include "replace.h"
#include "ceaser.h"

using namespace std;

void die()
{
	cout << "[error] Unexpected call. Aborting" << endl;
	cout << "Try to use ./mycrypto.bin -key1 -key2 your_string key_phrase " << endl;
	cout << "Where -key1 is key -e for encrypt and -d for decrypt" << endl;
	cout << "And -key2 is -s for replace Chipher and -c for Ceaser Chipher " << endl;
	cout << "So key_phraze is a value of replace or key keyionaries " << endl;
	abort();
}

int main(int argc, const char* argv[])
{

	// Small usage guide

	if (!((argc == 5) && (argv[1][0] == '-') && (argv[2][0] == '-')))
	{
		die();
	}

	// Param to string

	string key_operation = string((const char *)argv[1]);
	string key_type_chipher = string((const char *)argv[2]);
	string str = string(argv[3]);

	// Simple Replace Cipher

	if (key_type_chipher == string("-s"))
	{
		string key = string(argv[4]);
		Replace cipher(str, key);

		if (key_operation == string("-e"))
		{
			cout << cipher.encrypt() << endl;
			return 0;
		}

		else if (key_operation == string("-d"))
		{
			cout << cipher.decrypt() << endl;
			return 0;
		}

		// Not valid operation key
		else {
			cout << "Not valid key " << key_operation << endl;
			die();
		}
	}

	// Ceaser Cipher

	else if (key_type_chipher == string("-c"))
	{
		int replace_key = atoi(argv[4]);
		Ceaser cipher(str, replace_key);

		if (key_operation == string("-e"))
		{
			cout << cipher.encrypt() << endl;
			return 0;
		}

		else if (key_operation == string("-d"))
		{
			cout << cipher.decrypt() << endl;
			return 0;
		}

		// Not valid operation key
		else {
			cout << "Not valid key " << key_operation << endl;
			die();
		}
	}

	// Not valids type of operation key

	die();
	return 1;
}