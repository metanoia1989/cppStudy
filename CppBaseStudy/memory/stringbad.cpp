#include <cstring>
#include "stringbad.h"
using std::cout;

// 初始化静态类成员
int StringBad::num_strings = 0;

// 构造函数
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s); // 初始化指针
    num_strings++;
    cout << num_strings << ": \"" << str 
        << "\" object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str 
        << "\" default object created\n";
}

// 析构函数
StringBad::~StringBad()
{
    cout << "\"" <<str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}