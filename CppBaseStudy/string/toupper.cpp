#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s("Hello World!!!");

    // 字符串转化就成大写
    for (auto &c : s) {
        c = toupper(c);
    }
    cout << s << endl;

    string s2("some string");
    if (!s2.empty()) {
        s2[0] = toupper(s2[0]);
    }
    cout << s2 << endl;
}