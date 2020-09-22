#include <memory>

using namespace std;

int main()
{
    {
        // p 和 p2 指向动态分配的对象
        Sales_data *p = new Sales_data; // p 是内置指针
        auto p2 = make_shared<Sales_data>(); // p2 是一个 shared_tr
        Sales_data item(*p); // 拷贝构造函数将 *p 拷贝到 item 中
        vector<Sales_data> vec; // 局部对象
        vec.push_back(*p2); // 拷贝 p2 指向的对象
        delete p;   // 对 p 指向的对象执行析构函数
    } // 退出局部作用域 对 item, p2 和 vec调用析构函数
    // 销毁 p2 会递减其引用计数，如果引用计数为0，对象被释放
    // 销毁 vec 会销毁它的元素
}