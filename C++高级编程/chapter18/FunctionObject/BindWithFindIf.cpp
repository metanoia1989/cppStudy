#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;

    vector<int> myVector;
    while (true) {
        cout << "Enter a test score to add (0 to top): ";
        cin >> num;
        if(num == 0) {
            break;
        }
        myVector.push_back(num);
    }

    auto endIter = end(myVector);
    auto it = find_if(begin(myVector), endIter, bind(greater_equal<>(), placeholders::_1, 100));
    // auto it = find_if(begin(myVector), endIter, [](int i){ return i >= 100;});

    if (it == endIter) {
        cout << "No perfect scores" << endl;
    } else {
        cout << "Found a 'perfect' score of" << *it << endl;
    }

    return 0;
}
