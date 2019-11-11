#include <iostream>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{
    array<int, 3> arr = { 9, 8, 7 };
    cout << "Array size = " << arr.size() << endl;

    for (const auto& i : arr) {
        cout << i << endl;
    }

    cout << "Performing arr.fill(3).." << endl;
    arr.fill(3);

    for (auto iter = cbegin(arr); iter != cend(arr); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
