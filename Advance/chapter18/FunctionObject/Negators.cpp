#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>


using namespace std;

bool perfectScore(int num)
{
    return (num >= 100);
}

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
    auto it = find_if(begin(myVector), endIter, not_fn(perfectScore));

    if (it == endIter) {
        cout << "No perfect scores" << endl;
    } else {
        cout << "Found a 'less-then-perfect' score of " << *it << endl;
    }

    return 0;
}
