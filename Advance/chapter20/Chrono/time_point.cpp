#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    // 稳定时钟的纪元
    time_point<steady_clock> tp1;

    tp1 += minutes(10);

    // 获取时间戳
    auto d1 = tp1.time_since_epoch();

    // 转换为秒
    duration<double> d2(d1);
    cout << d2.count() << " seconds" << endl;
    

    return 0;
}
