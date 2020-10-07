#include <iostream>

int main(int argc, char const *argv[])
{
    auto result = 0xFF & 0xF + 2;
    std::cout << "答案结果为:" << result << std::endl;
    return 0;
}
