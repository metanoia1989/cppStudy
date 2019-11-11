#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
    for (auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<string> vec;

    vec.emplace_back(5, 'a');

    printVector(vec);

    return 0;
}
