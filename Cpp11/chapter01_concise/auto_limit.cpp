// 以下是C++11中的auto限制

void func(auto a = 1) {} // error: auto 不能用于函数参数

struct Foo
{
    auto var1 = 0; // error: auto 不能用于非静态成员变量
    static const auto var2_ = 0;  
}

template <typename T>
struct Bar {};

int main(void)
{
    int arr[10] = {0};
    auto aa = arr; // aa -> int *
    auto rr[10] = arr; // error: auto无法定义数组
    Bar<int> bar;
    Bar<auto> bb = bar; // error: auto无法推导出模板参数

    return 0;
}