#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main(int argc, char const *argv[])
{
    tuple<int, string, bool> t1(16, "Test", true);
    auto [i, str, b] = t1;
    cout << "Decomposed: i = " << i << ", str = '" << str << "', b = " << b << endl;

    return 0;
}
