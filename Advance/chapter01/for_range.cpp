#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

int main(int argc, char const *argv[])
{
    std::array<int, 4> arr = {1, 2, 3, 4};
    for (int i : arr) {
        std::cout << i << std::endl; 
    }
    
    return 0;
}
