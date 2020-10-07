#include <iostream>
#include <string>
#include <functional>

using namespace std;

void func(int num, const string& str)
{
    cout << "func(" << num << ", " << str << ")" << endl;
}

int main(int argc, char const *argv[])
{
    function<void(int, const string&)> f1 = func;
    // auto f1 = func;  // 这样的 f1 是函数指针
    f1(1, "test");

    return 0;
}
