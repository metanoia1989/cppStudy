#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    auto isGreaterThan100 = [](auto i) { return i > 100; };

    vector<int> ints{ 11, 55, 101, 200 };
    auto it1 = find_if(cbegin(ints), cend(ints), isGreaterThan100);
    if (it1 != cend(ints)) {
        cout << "Found a value > 100: " << *it1 << endl;
    }

    vector<double> doubles{ 11.1, 55.5, 200.2 };
    auto it2 = find_if(cbegin(doubles), cend(doubles), isGreaterThan100);
    if (it2 != cend(doubles)) {
        cout << "Found a value > 100: " << *it2 << endl;
    }

    return 0;
}
