#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> myMap = { { 4, 40 }, { 5, 50 }, { 6, 60 } };
    for_each(cbegin(myMap), cend(myMap), [](const auto& p)
        { cout << p.first << "->" << p.second << endl; });

    return 0;
}
