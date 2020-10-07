#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

// 移动算法 move() 在 <utility> 中定义，在容器之间移动元素
// move_backward() 跟 move() 有同样的机制，按从最后一个元素
// 向第一个元素的顺序移动

class MyClass
{
public:
    MyClass() = default;
    MyClass(const MyClass& src) = default;
    MyClass(string_view str) : mStr(str) {}
    virtual ~MyClass() = default;

    // 移动赋值运算符
    MyClass& operator=(MyClass&& rhs) noexcept 
    {
        if (this == &rhs) 
            return *this;
        mStr = std::move(rhs.mStr);
        cout << "Move operator= (mStr=" << mStr << ")" << endl;
        return *this;
    }

    void setString(string_view str) { mStr = str; }
    string_view getString() const { return mStr; }

private:
    string mStr;
};

int main(int argc, char const *argv[])
{
    vector<MyClass> vecSrc{ MyClass("a"), MyClass("b"), MyClass("c") };
    vector<MyClass> vecDst(vecSrc.size());
    move(begin(vecSrc), end(vecSrc), begin(vecDst));
    for (const auto& c : vecDst) { cout << c.getString() << ""; }

    return 0;
}
