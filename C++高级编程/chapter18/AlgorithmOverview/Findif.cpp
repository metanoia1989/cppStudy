#include <algorithm>
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
        cout << "Enter a test score to add (0 to stop): ";
        cin >> num;
        if (num == 0) {
            break;
        }
        myVector.push_back(num);
    }

    auto endIt = cend(myVector);
    auto it = find_if(cbegin(myVector), endIt, perfectScore);
    if (it == endIt) {
        cout << "No perfect scroes" << endl;
    } else {
        cout << "Found a 'prefect' score of " << *it << endl;
    }

    return 0;
}


