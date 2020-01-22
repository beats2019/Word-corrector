#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <fstream>
#include <string>
using std::string;
using std::ifstream;

class Dictionary
{
public:
	Dictionary();
	bool isKeyInDictionary(string);
	void exchangeCharacters(string, int=0);

private:
	ifstream database;
	string swap(const string&, int, int);

};

#endif // !DICTIONARY_H