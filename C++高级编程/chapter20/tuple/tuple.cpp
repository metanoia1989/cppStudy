#include <iostream>
#include <string>
#include <tuple>
#include <functional>   // ref() cref()
#include <typeinfo>

using namespace std;

int main(int argc, char const *argv[])
{
    using MyTuple = tuple<int, string, bool>;
    MyTuple t1(16, "Test", true);
    cout << "t1 = (" << get<0>(t1) << "," << get<1>(t1) 
        << ", " << get<2>(t1) << ")" << endl;
    cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;
    cout << "String = " << get<string>(t1) << endl;
    cout << "Tuple Size = " << tuple_size<MyTuple>::value << endl;
    cout << "Tuple Size = " << tuple_size<decltype(t1)>::value << endl;

    double d = 3.14;
    string str1 = "Test";
    auto t2 = make_tuple(16, ref(d), cref(d), ref(str1));
    // C++17 构造函数模板参数自动推导
    std::tuple t3(16, ref(d), cref(d), ref(str1));

    cout << "d = " << d << endl;
    get<1>(t2) *= 2;
    cout << "d = " << d << endl;

    return 0;
}
