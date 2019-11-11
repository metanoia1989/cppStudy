#include <iostream>

using namespace std;

template<unsigned int f>
class Factorial
{
public:
    static const unsigned long long val = (f * Factorial<f - 1>::val);
};

template<>
class Factorial<0>
{
public:
    static const unsigned long long val = 1;
};

int main(int argc, char const *argv[])
{
    cout << Factorial<6>::val << endl;
    return 0;
}
