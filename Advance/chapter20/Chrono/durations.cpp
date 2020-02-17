#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    // 指定滴答周期为60秒的持续时间
    duration<long, ratio<60>> d1(123);
    cout << d1.count() << endl;

    //指定由双精度号表示的持续时间
    //等于1秒并为其分配最大可能的持续时间。
    duration<double> d2;
    d2 = d2.max();
    cout << d2.count() << endl;

    // 定义两个持续时间，一个滴答周期为1分钟 一个为1秒钟
    duration<long, ratio<60>> d3(10);   // 10 minutes
    duration<long, ratio<1>> d4(14);   // 14 seconds

    if (d3 > d4) {
        cout << "d3 > d4" << endl;
    } else {
        cout << "d3 <= d4" << endl;
    }
    // d4 自增一秒
    ++d4;

    // d4 乘以2
    d4 *= 2;

    // 两个持续时间相加存储为分钟
    duration<double, ratio<60>> d5 = d3 + d4;

    // 两个持续时间相加存储为秒钟
    duration<double, ratio<61>> d6 = d3 + d4;
    cout << d3.count() << " minutes + " << d4.count() << " seconds = "
        << d5.count() << " minutes or " << d6.count() << " seconds" << endl;

    // 创建30秒的持续时间
    duration<long> d7(30);

    // 将d7从秒转换为分钟
    duration<double, ratio<60>> d8(d7);
    cout << d7.count() << " seconds = " << d8.count() << " minutes" << endl;

    // 将d7显式从秒转换为分钟
    auto d8_ = duration_cast<duration<long, ratio<60>>>(d7); 
    cout << d8_.count() << endl;

    // 将整数分钟转换为整数秒
    duration<long, ratio<60>> d9(10);
    duration<long> d10(d9); // 秒
    cout << d10.count() << endl;

    // 使用预定义的持续时间
    auto t = hours(1) + minutes(23) + seconds(45);
    cout << seconds(t).count() << " seconds" << endl;

    // 标准用户预定义字面量
    auto myDuration = 42min;

    return 0;
}
