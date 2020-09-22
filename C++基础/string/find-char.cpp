#include <iostream>
#include <string>

using std::string;

// 返回 s 中 c 第一次出现的位置索引
// 引用形参 occurs 负责统计 c 出现的总次数
string::size_type find_char(const string &s, char c, 
    string::size_type &occurs)
{
    auto ret = s.size(); // 第一次的出现的位置
    occurs = 0; // 设置表示出现次数的形参的值
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret; // 出现次数通过 occurs 隐式返回
}