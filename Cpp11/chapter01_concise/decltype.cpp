#include <iostream>
#include <typeinfo>
#include <string>

// decltype 用来在编译时推导出一个表达式的类型
// sizeof 用来推导表达式类型大小

int main(int argc, char const *argv[])
{
    int x = 0;
    decltype(x) y = 1; // y -> int
    decltype(x + y) z = 0; // z -> int

    const int& i = x;

    std::cout << "y type: " << typeid(y).name() << '\n';

    return 0;
}


