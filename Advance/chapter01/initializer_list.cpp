#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int makeSum(initializer_list<int> lst) 
{
    int total = 0;
    for (int value : lst) {
        total += value;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int a = makeSum({1, 2, 3});
    int b = makeSum({10, 20, 30, 40, 50, 60});
    cout << a << b;

    return 0;
}
