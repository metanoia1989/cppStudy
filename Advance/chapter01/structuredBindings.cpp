#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

int main(int argc, char const *argv[])
{
    std::array<int, 3> values = {11, 22, 33};
    auto [x, y, z] = values;

    struct Point { double mX, mY, mZ; };
    Point point;
    point.mX = 1.0; point.mY = 2.0; point.mZ = 3.0;
    auto [ a, b, c ] = point;

    cout << x << "," << y << "," << z << endl;
    cout << a << "," << b << "," << c;

    return 0;
}
