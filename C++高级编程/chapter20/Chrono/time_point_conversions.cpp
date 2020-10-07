#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    {
        time_point<steady_clock, seconds> tpSeconds(42s);
        // 将秒转换为毫秒
        time_point<steady_clock, milliseconds> tpMilliseconds(tpSeconds);

        cout << tpMilliseconds.time_since_epoch().count() << " ms" << endl;
    }

    {
        time_point<steady_clock, milliseconds> tpMilliseconds(42'424ms);
        // 将毫秒显式转换为秒
        time_point<steady_clock, seconds> tpSeconds(
            time_point_cast<seconds>(tpMilliseconds));
        
        // 将秒转换为毫秒再输出
        milliseconds ms(tpSeconds.time_since_epoch());
        cout << ms.count() << " ms" << endl;
    }

    return 0;
}
