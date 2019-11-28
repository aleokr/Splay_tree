#include "tests.h"
#include "functions.h"
#include "TreeMap.h"
#include "Benchmark.h"

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    TreeMap<string,string> dict1;
	map<string, string> map1;

	string key;

    int howmany;
    cout << "Ile slow wczytac i wyszukać?" << endl;
    cin >> howmany;

    Benchmark<std::chrono::microseconds> b1;
    read_file_TreeMap("src/pan_tadeusz.txt", dict1, howmany);
    size_t elapsed1 = b1.elapsed();
    cout << "TreeMap wczytywanie " << howmany << " slow: " << elapsed1 << " micros" << endl;

	Benchmark<std::chrono::microseconds> b2;
	readFileToMap("src/pan_tadeusz.txt", map1, howmany);
    size_t elapsed2 = b2.elapsed();
    cout << "Map wczytywanie " << howmany << " slow: " << elapsed2 << " micros" << endl;

    Benchmark<std::chrono::microseconds> b3;
    for(int i=0; i<howmany; i++)
    {
        key=to_string(i);
        dict1.value(key);

    }
    size_t elapsed3 = b3.elapsed();
    cout << "TreeMap szukanie " << howmany << " slow: " << elapsed3 << " micros" << endl;

	Benchmark<std::chrono::microseconds> b4;
    for(int i=0; i<howmany; i++)
    {
        key=to_string(i);
        map1.find(key);

    }
    size_t elapsed4 = b4.elapsed();
    cout << "TreeMap szukanie " << howmany << " slow: " << elapsed4 << " micros" << endl;


    unit_test();
    return 0;
}
