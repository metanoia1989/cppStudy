#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <array>

int main()
{
    // 用聚合初始化构造
    std::array<int, 3> a1{1, 2, 3};
    std::array<int, 3> a2{1, 2, 3};
    std::array<std::string, 2> a3 = {std::string("a"), "b"};

    // 支持容器操作
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), 
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    // 支持待范围 for 循环
    for (const auto & s : a3) {
        std::cout << s << ' ';
    }
}