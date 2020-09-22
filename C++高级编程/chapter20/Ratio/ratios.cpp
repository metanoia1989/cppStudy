#include <iostream>
#include <ratio>

using namespace std;

int main(int argc, char const *argv[])
{
    // 定义编译时有理数
    using r1 = ratio<1, 60>;
    cout << "1) " << r1::num << "/" << r1::den << endl;

    // 获取分子和分母
    intmax_t num = r1::num;
    intmax_t den = r1::den;
    cout << "2) " << num << "/" << den << endl;

    // 两个有理数相加
    using r2 = ratio<1, 30>;
    cout << "3) " << r2::num << "/" << r2::den << endl;
    using result = ratio_add<r1, r2>::type;
    cout << "4) " << result::num << "/" << result::den << endl;

    // 比较两个有理数
    using res = ratio_less<r2, r1>;
    cout << "5) " << boolalpha << res::value << endl;


    return 0;
}
