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

int main()
{
    ifstream dictionaryInput("dictionary.dat", ios::in);

    if (!dictionaryInput)
    {
        cerr << "File not opened";
        exit(1);
    }

    string searchKey, actualWord;
    cout << "Enter the search key: ";
    cin >> searchKey;
    bool foundKey = false;

    while(dictionaryInput >> actualWord)
        if (searchKey == actualWord)
        {
            foundKey = true;
            break;
        }
    if (foundKey)
        cout << "The word is correctly written" << endl;
    else
        cout << "The word" << searchKey << "is not correct" << endl;


    
       




}

