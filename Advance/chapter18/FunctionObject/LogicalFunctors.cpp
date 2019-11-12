#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

bool allTrue(const vector<bool>& flags)
{
    return accumulate(cbegin(flags), cend(flags), true, logical_and<>());
}

bool anyTrue(const vector<bool>& flags)
{
    return accumulate(cbegin(flags), cend(flags), false, logical_or<>());
}

int main(int argc, char const *argv[])
{
    vector<bool> myVector;

    int num;

    while (true) {
        cout << "Enter a value 0 or 1 to add (-1 to stop): ";
        cin >> num;
        if (num == -1) {
            break;
        }
        myVector.push_back(num == 1);
    }
    cout << "allTrue? " << (allTrue(myVector) ? "yes" : "no") << endl;
    cout << "anyTrue? " << (anyTrue(myVector) ? "yes" : "no") << endl;

    return 0;
}
