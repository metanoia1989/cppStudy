#include <iostream>

using namespace std;

int main()
{
    int a = 123;
    auto f = [=] { cout << a << endl; }; // 值捕获 
    f(); 

    int b = 245;
    auto f2 = [&] { cout << b << endl; }; // 引用捕获
    f2();

    int c = 234234;
    auto f3 = [c] () mutable { cout << ++c << endl; }; 
    f3();
    cout << c << endl;
}