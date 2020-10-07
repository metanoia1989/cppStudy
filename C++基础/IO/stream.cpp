#include <iostream>

using namespace std;

void process_input(istream &);

int main()
{
    // 记住 cin 的当前状态
    auto old_state = cin.rdstate();
    cin.clear(); // 重置 cin 状态，使其有效
    process_input(cin); // 使用cin
    cin.setstate(old_state); // 将 cin 置为原有状态
    // 复位 failbit 和 badbit，保持其他标志位不变
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}