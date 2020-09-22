#include <complex>
#include <string>

// 用熟模式字面量运算符实现了用户定义的字面量 _i，_i用来定义一个复数字面量
std::complex<long double> operator"" _i(long double d)
{
    return std::complex<long double>(0, d);
}

// 用熟模式字面量运算符实现了用户定义的字面量 _s，_s用来定义std::string字面量
std::string operator"" _s(const char* str, size_t len)
{
    return std::string(str, len);
}

// 生模式字面量运算符需要一个 const char* 类型的参数，下面是 \0 结尾的C风格字符串
// std::complex<long double> operator"" _c(const char* p)
// {

// }


int main(int argc, char const *argv[])
{
    std::complex<long double> c1 = 9.634_i;
    auto c2 = 1.23_i;

    std::string str1 = "Hello World"_s;
    auto str2 = "Hello world"_s;
    // 没有 _s 字面量，自动推导的类型是 cosnt char*
    auto str3 = "Hello world";
    return 0;
}
