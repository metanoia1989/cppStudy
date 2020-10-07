#include <iostream>
#include <string>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;
using std::string;

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

class ErrCode
{
private:
    /* data */
public:
    ErrCode(int i){}
    string msg() { return string("hello "); }
    ~ErrCode(){}
};

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << "; ";
    for (const auto &elem : il) {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    string expected = "hello";
    string actual = "hahah";
    // 向 initializer_list 传递一个值的序列，使用花括号
    if (expected != actual) {
        error_msg(ErrCode(42), {"functionX", expected, actual});
    } else {
        error_msg(ErrCode(0), {"functionX", "okay"});
    }

    return 0;
}