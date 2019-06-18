#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string hexdigits = "0123456789ABCDEF"; // 可能的十六进制数字
    cout << "Enter a series of numbers between 0 and 15"
        << " separated by spaces. Hit ENTER when finished: "
        << endl;
    string result; // 用于保存十六进制字符串
    string::size_type n; // 用于保存从输入流读取的数
    while (cin >> n) {
        if (n < hexdigits.size()) { // 忽略无效输入
            result += hexdigits[n];
        }
    }
    cout << "Your hex number is: " << result << endl;
}