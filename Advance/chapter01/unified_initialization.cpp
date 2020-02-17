//
// Created by Administrator on 2019/9/27.
//

static CircleStruct
{
    int x, y;
    double radius;
};

class CircleClass
{
private:
    int mX, mY;
    double  mRadius;
public:
    CircleClass(int x, int y, double radius)
        : mX(x), mY(y), mRadius(radius) {}
};

int main()
{
    // C++11 之前类只能用函数符号()调用构造函数
    CircleStruct myCircle = {10, 10, 2.5};
    CircleClass myCircle2(10, 10, 2.5);

    // C++11之后统一使用 {} 初始化
    CircleStruct myCircle3 = {10, 10, 2.5};
    CircleClass myCircle4 = {10, 10, 2.5};
    // 等号是可选的
    CircleStruct myCircle5{10, 10, 2.5};
    CircleClass myCircle6{10, 10, 2.5};

    // 统一初始化可以初始化其他类型
    int a = 3;
    int b(3);
    int c = {3};
    int d{3};
    // 统一初始化可以将变量初始化为0，指针初始化为nullptr

    // 统一初始化会阻止C++隐式窄化
    int x = {3.14}; // 报错

    // 统一初始化动态分配数组
    int* pArray = new int[4]{0, 1, 2, 3};

    /* 直接列表初始化与复制列表初始化 */
    // 复制列表初始化
    auto a = {11}; // initializer_list<int>
    auto b = {11, 22};  // initializer_list<int>
    auto b = {11, 22.33};   // error, 复制列表初始化，初始化器里的所有元素类型必须一致

    // 直接列表初始化
    auto c {11};    // int
    auto d {11, 22};    // error, too many elements.
    // 早期标准版本 直接列表初始化 上述代码都为 initializer_list<int>

    return 0;
}
