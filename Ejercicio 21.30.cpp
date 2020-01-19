#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ios;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <cstdlib>
using std::exit;
#include <string>
using std::string;
using namespace std;

bool isKeyInDictionary(string, ifstream&);

int main()
{
    ifstream dictionaryInput("dictionary.dat", ios::in);

    if (!dictionaryInput)
    {
        cerr << "File not opened";
        exit(1);
    }

    string searchKey;
    cout << "Enter the search key: ";
    cin >> searchKey;

    if (isKeyInDictionary(searchKey, dictionaryInput))
        cout << "The word you typed was correctly found in the dictionary!" << endl;
    else
        cout << "The word " << searchKey << " is not correct" << endl;
}


/*
    Search a given key in the dictionary and returns true if the 
    key was found.

    @param key The string to be searched
    @param dictionary The english dictionary(database)
*/
bool isKeyInDictionary(string key, ifstream& dictionary)
{
    dictionary.seekg(0);
    string actualWord;
    bool found = false;
    while (dictionary >> actualWord)
        if (key == actualWord)
        {
            found = true;
            break;
        }
    return found;
}

