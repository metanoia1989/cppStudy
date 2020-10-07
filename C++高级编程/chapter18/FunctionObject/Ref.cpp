#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

void increment(int& value)
{
    ++value;
}

int main(int argc, char const *argv[])
{
    int index = 0;
    increment(index);
    cout << "current index: " << index << endl;

    index = 0;
    auto incr1 = bind(increment, index);
    incr1();
    cout << "current index: " << index << endl;

    index = 0;
    auto incr2 = bind(increment, ref(index));
    incr2();
    cout << "current index: " << index << endl;

    return 0;
}
