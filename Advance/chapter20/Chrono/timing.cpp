#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// 计算程序执行时间

int main(int argc, char const *argv[])
{
    // 获取开始时间
    auto start = high_resolution_clock::now();

    // 执行要测量的代码
    double d = 0;
    for (size_t i = 0; i < 1000000; i++) {
        d += sqrt(sin(i) * cos(i));
    }

    // 获取结束时间 并且计算时间差
    auto end = high_resolution_clock::now();
    auto diff = end - start;
    // 将时间差转换为毫秒并输出
    cout << duration<double, milli>(diff).count() << "ms" << endl;
    
    // 输出d，否则编译器可能优化掉上面的整个循环。
    cout << d << endl;

    return 0;
}
