#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>
class StringBad
{
private:
    char * str; // 字符串指针
    int len; // 字符串长度
    static int num_strings; // 数字对象
public:
    StringBad(const char * s);
    StringBad();
    ~StringBad();
    // friend function
    friend std::ostream & 
        operator<<(std::ostream & os, const StringBad & st);
};

#endif