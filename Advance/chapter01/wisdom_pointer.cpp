#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    auto anInts = std::make_shared<int[]>(5);
    if (anInts) {
        std::cout << anInts[0];
    }
    return 0;
}
