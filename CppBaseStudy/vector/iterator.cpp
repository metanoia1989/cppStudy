#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    auto b = v.begin();
    auto e = v.end();

    for(auto iter = b; iter != e; ++iter) {
        cout << *iter << endl;
    }

    // 反向输出容器中的元素
    auto rb =  v.rbegin();
    auto re =  v.rend();

    for(auto iter = rb; iter != re; ++iter) {
        cout << *iter << endl;
    }

    // 进行迭代器的运算，输出容器中间的元素
    auto mid = v.begin() + v.size() / 2;
    cout << "该容器中间的元素为：" << *mid << endl;
}