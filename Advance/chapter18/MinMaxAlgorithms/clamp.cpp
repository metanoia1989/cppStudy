#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << clamp(-3, 1, 10) << endl;
    cout << clamp(3, 1, 10) << endl;
    cout << clamp(22, 1, 10) << endl;

    return 0;
}
