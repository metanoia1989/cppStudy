#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

int main(int argc, char const *argv[])
{
    array<int, 3> arr = {9, 8, 7};
    cout << "Array size = " << arr.size() << endl;
    cout << "2nd element = " << arr[1] << endl;
    return 0;
}
