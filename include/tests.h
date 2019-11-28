#include "TreeMap.h"
#include "functions.h"

#include <iostream>
#include <cassert>
#include <map>

using namespace std;

void unit_test()
{
    TreeMap<string,string> dict;
    map<string, string> map1;

    // slownik jest pusty
    assert(dict.isEmpty() == true);
    assert(map1.empty()==true);

    assert(dict.contains("0") == false);
    assert(map1.count("0")==false);

    // dodanie elementu do slownika
    read_file_TreeMap("src/pan_tadeusz.txt", dict, 5);

    readFileToMap("src/pan_tadeusz.txt", map1, 5);

    assert(dict.isEmpty() == false);
    assert(map1.empty() == false);

    //cout << dict.size() << endl;
    //cout << map1.size() << endl;

    assert(dict.contains("0") == true);
    assert((dict.value("0")).compare("Adam") == 0);

    assert(map1.count("0") == true);
    assert((map1.find("0")->second).compare("Adam") == 0);

    // dodanie elementu  jako pary
    //dict.insert(std::pair<int,int>(1, 2));
    // assert(dict.size() == 2);
    //assert(dict.contains(1) == true);
    //assert(dict.value(0) == 1);
    //assert(dict.value(1) == 2);

    //operator []
    assert((dict["0"]).compare("Adam") == 0);
    assert((dict["1"]).compare("Mickiewicz") == 0);

    assert((map1["0"]).compare("Adam") == 0);
    assert((map1["1"]).compare("Mickiewicz") == 0);

    //operator [] tworzy nowy element
    dict["5"] = "ostatni";
    assert((dict["5"]).compare("ostatni") == 0);

    //assert(dict.size() == 3);


    // // nadpisanie wartosci dla istniejacego elementu
    // dict.insert(2, 4);
    // assert(dict.size() == 3);
    // assert(dict.value(2) == 4);


}
