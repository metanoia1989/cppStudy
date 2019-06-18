#include <iostream>

int main()
{
    auto i = 1ULL;
    int length = sizeof(i);
    std::cout << length;
    return 0;
}