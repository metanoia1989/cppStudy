#include <iostream>
// 类型推导 auto，本质上是编译器根据字面量来推断类型然后进行替换。  
// auto并不能代表一个实际的类型声明（如s的编译错误），只是一个类型声明的“占位符”。
// 使用auto声明的变量必须马上初始化，以让编译器推断出它的实际类型，并在编译时将auto占位符替换为真正的类型。

//  auto关键字其实并不是一个全新的关键字。在旧标准中，它代表“具有自动存储期的局部变量”，不过其实它在这方面的作用不大，
// auto int是旧标准中auto的使用方法。与之相对的是下面的static int，它代表了静态类型的定义方法。
// 实际上，我们很少有机会这样直接使用auto，因为非static的局部变量默认就是“具有自动存储期的”
// 考虑到auto C++中使用的较少，在c++11标准中，auto关键字不再表示存储类型指示符（storage-class-specifiers），
// 如上文提到的static，以及register， mutable等），而是改成了一个类型指示符（type-specifier），
// 用来提示编译器对此类型的变量做类型的自动推导。

int main(int argc, char const *argv[])
{
    /* auto类型推导新意义 */
    auto x = 5; // x 是int类型
    auto pi = new auto(1); // pi被推导为int*
    const auto *v = &x, u = 6; // v 是 const int*类型，u是const int类型
    static auto y = 0.0; // y是double类型
    // auto int r; // auto 不在表示存储类型指示符
    // auto s; // auto 无法推导出s的类型

    std::cout << x;

    /* auto推导规则 */ 
    // auto 可以同指针、引用结合起来使用，还可以带上cv限定符（cv-qualifier，const和volatile限定符的统称）
    // 1）当不声明为指针或引用时，auto的推导结果和初始化表达式抛弃引用和cv限定符后类型一致。
    // 2）当声明为指针或引用时，auto的推导结果将保持初始化表达式的cv属性。
    int x = 0;
    auto *a = &x; // a -> int*, auto 被推导为 int
    auto b  &x; // b -> int*, auto 被推导为 int*
    auto & c = x; // c -> int&, auto 被推导为int
    auto d = c; // d -> int, auto 被推导为int

    const auto e = x; // e -> const int
    auto f = e; // f -> int

    const auto& g = x; // g -> const int&
    auto& h = g; // h -> const int&

    return 0;
}


// auto的推导和函数模板参数的推导很相似
template <typename T> void func(T x) {} // T -> auto
template <typename T> void func(T *x) {} // T * -> auto *
template <typename T> void func(T &x) {} // T & -> auto &
template <typename T> void func(const T x) {} // const T -> const auto
template <typename T> void func(const T *x) {} // const T * -> const auto *
template <typename T> void func(const T &x) {} // const T & -> const auto &