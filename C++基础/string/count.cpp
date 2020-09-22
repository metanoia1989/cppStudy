#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("Hello World!!!");

    decltype(s.size()) punct_cnt = 0;
    // 统计 s 中标点符号的数量
    for (auto c : s) {
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " Punctuation charcters in " << s << endl;
}