#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str(u8"你好啊 哈哈哈");

    for (auto c : str)
        cout << c << endl;
    cout << "测试手动阀手动阀";
}