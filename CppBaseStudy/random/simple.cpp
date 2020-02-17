#include <iostream>
#include <random>

using namespace std;

int main()
{
    default_random_engine e; // 生成随机无符号数 
    for (size_t i = 0; i < 10; i++) {
        cout << e() << " "; // 调用 对象 e() 生成下一个随机数
    }

    // 生成 0 到 9 之间的均匀分布的随机数
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine f;
    for (size_t i = 0; i < 10; i++) {
        cout << u(f) << " "; // u作为随机数源，每个调用返回在指定范围内均匀分布的值
    }
}