#include "Dictionary.h"
#include <fstream>
using std::ifstream;
using std::ios;
#include <string>
using std::string;
using std::getline;
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;


Dictionary::Dictionary()
{
    database.open("dictionary.dat", ios::in);
    if (!database)
    {
        cerr << "Could not open dictionary";
        exit(1);
    }
}


/*
    Search a given key in the dictionary and returns true if the
    key was found.

    @param key The string to be searched  
*/
bool Dictionary::isKeyInDictionary(string key)
{
    database.seekg(0);
    
    string currentWord("");
    while (database >> currentWord)
        if (key == currentWord)
            return true;
    database.clear();
    return false;
}


/*
    Search every permutations of a given string in the dictionary
    Note: All the characters of the string must be different, otherwise
    there will be duplicate results

    @param characters String to be exchanged
    @param startPosition Start position of the string to be operated
*/
void Dictionary::exchangeCharacters(string characters, int startPosition)
{
    int charactersLength = characters.length();
    if (startPosition == charactersLength - 1 and isKeyInDictionary(characters))
        cout << "Possible solution with " << characters << endl;
    else
        for (int t = startPosition; t <= (charactersLength - 1); t++)
        {
            string temporalString = swap(characters, startPosition, t);
            exchangeCharacters(temporalString, startPosition + 1);
        }
}


/*
    Swap the values of two given positions of a string
    @param cad The string where the characters will be swaped
    @param pos_a , pos_b String positions to be swaped
*/
string Dictionary::swap(const string& cad, int pos_a, int pos_b)
{
    string resultString = cad;
    char temp = resultString[pos_a];
    resultString[pos_a] = resultString[pos_b];
    resultString[pos_b] = temp;
    return resultString;
}

