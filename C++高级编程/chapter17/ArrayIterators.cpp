#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const size_t count = 10;
    int arr[count];

    for (int i = 0; i < count; i++) {
        arr[i] = i;
    }

    vector<int> vec;
    vec.insert(end(vec), arr, arr + count);

    for (const auto& i : vec) {
        cout << i << " ";
    }

    return 0;
}
