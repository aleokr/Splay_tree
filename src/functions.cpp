#include "functions.h"
#include <fstream>

void read_file( std::string fileName, TreeMap<std::string, std::string>& tree, int howManyWords)
{
    std::fstream myReadFile;
    myReadFile.open(fileName);
    std::string word;

    if (myReadFile.is_open())
    {
        int wordsCounter=0;
        while ( myReadFile>>word && wordsCounter < howManyWords )
        {
            tree.insert( word, " " );
            ++wordsCounter;
        }
    }
}

void readFileToMap( std::string fileName, std::map<char, std::string>& map1, int howManyWords)
{
    std::fstream myReadFile;
    myReadFile.open(fileName);
    std::string word;

    if (myReadFile.is_open())
    {
        int wordsCounter=0;
        while ( myReadFile>>word && wordsCounter < howManyWords )
        {
            map1.insert ( std::pair<char,std::string>('a',word) );
            ++wordsCounter;
        }
    }
}
