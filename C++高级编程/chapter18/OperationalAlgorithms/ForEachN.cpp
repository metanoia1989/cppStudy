#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

// for_each_n 只需要范围的起始迭代器、要迭代元素的数量以及函数回调
// 返回的迭代器等于 begin + n，且不会执行任何边界检查

int main(int argc, char const *argv[])
{
    map<int, int> myMap = { { 4, 40 }, { 5, 50 }, { 6, 60 } };
    for_each_n(cbegin(myMap), 2, [](const auto& p) {
        cout << p.first << "->" << p.second << endl;
    });

    return 0;
}
