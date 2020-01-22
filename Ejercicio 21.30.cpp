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
using std::strlen;


#include "Dictionary.h"


int main()
{
    
    Dictionary englishDictionary;
    string inputString;

    cout << "Please input a word: ";
    cin >> inputString;

    
    if (englishDictionary.isKeyInDictionary(inputString))
        cout << "The word " << inputString << " was correctly found in the dictionary" << endl;
    else
        englishDictionary.exchangeCharacters(inputString);
    

    return 0;
}


