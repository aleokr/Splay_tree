#include "functions.h"

#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

void read_file_TreeMap( std::string fileName, TreeMap<std::string, std::string> &tree, int howManyWords)
{
    std::ifstream myReadFile;
    myReadFile.open(fileName);
    std::string word;

    if (myReadFile.is_open())
    {
        int wordsCounter=0;
        string key;
        while ( myReadFile>>word && wordsCounter < howManyWords )
        {
            key= to_string(wordsCounter);
            tree.insert(key, word);// niepara
            //tree.insert( std::pair<std::string,std::string>(key ,word)); //para
            ++wordsCounter;
        }
    }
}

void readFileToMap( std::string fileName, std::map<std::string, std::string> &map1, int howManyWords)
{
    std::ifstream myReadFile;
    myReadFile.open(fileName);
    std::string word;

    if (myReadFile.is_open())
    {
        int wordsCounter=0;
        string key;
        while ( myReadFile>>word && wordsCounter < howManyWords )
        {
            key= to_string(wordsCounter);
            map1.insert ( std::pair<std::string,std::string>(key ,word));
            ++wordsCounter;
        }
    }
}
