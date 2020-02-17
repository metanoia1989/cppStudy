#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    // 获取当前时间的时点
    system_clock::time_point tpoint = system_clock::now();

    // 转换为C风格时间
    time_t tt = system_clock::to_time_t(tpoint);

    // 转换为本地时间
    tm* t = localtime(&tt);
    // 输出到控制台
    cout << put_time(t, "%H:%M:%S") << endl;

    return 0;
}
