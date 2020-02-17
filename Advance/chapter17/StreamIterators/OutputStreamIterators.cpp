#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> myVector(10);
    iota(begin(myVector), end(myVector), 1);

    copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
