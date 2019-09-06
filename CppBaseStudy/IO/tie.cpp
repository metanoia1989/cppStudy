#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ostream *prevstr;
    std::ofstream ofs;
    ofs.open("test.txt");

    std::cout << "tie example:\n"; // 直接输出到屏幕

    *std::cin.tie() << "This is inserted into the cout\n"; // 空参数调用返回 默认的 output stream 即 cout
    prevstr = std::cin.tie(&ofs); // cin 绑定 ofs，返回原来的 output stream
    *std::cin.tie() << "This is inserted into the file\n"; // ofs 输出到文件
    std::cin.tie(prevstr); // 恢复 cin cout 的绑定

    ofs.close();
    system("pause");
    return 0;
}
