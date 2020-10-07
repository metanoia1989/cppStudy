#include <iostream>
#include <regex>

using namespace std;

int main()
{
    // 第一种存储方式
    // match_results<string::const_iterator> result;
    // 第二种存储方式
    smatch result;

    // 文本数据
    string str = "1994 is my birth year 1994";
    // 正则表达式
    string regex_str("\\d{4}");
    regex pattern1(regex_str, regex::icase);

    // 迭代器声明
    string::const_iterator iter = str.begin();
    string::const_iterator iterEnd = str.end();
    string temp;

    // 正则查找
    while (std::regex_search(iter, iterEnd, result, pattern1))
    {
        temp = result[0];
        cout << temp << endl;
        iter = result[0].second; // 更新搜索起始位置
    }

    // 正则匹配
    string regex_str2("(\\d{4}.*)");
    regex pattern2(regex_str2, regex::icase);

    if(regex_match(str, result, pattern2)) {
        cout << result[0] << endl;
        cout << result[1] << endl;
    }
     
    // 正则替换
    std::regex reg1("\\d{4}");
    string t("1993");
    str = regex_replace(str, reg1, t); // trim_left
    cout << str << endl;

    return 0;
}