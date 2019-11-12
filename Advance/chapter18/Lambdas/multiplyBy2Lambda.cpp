#include <iostream>
#include <functional>

using namespace std;

// function<int(void)> multiplyBy2Lambda(int x)
// {
//     return [x]{ return 2 * x; };
// }

auto multiplyBy2Lambda(int x)
{
    return [x]{ return 2 * x; };
}

int main(int argc, char const *argv[])
{
    auto fn = multiplyBy2Lambda(5);
    cout << fn() << endl;

    return 0;
}
