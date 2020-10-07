#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

// 比较算法

// 模板函数，容器必须支持 push_back()
template<typename Container>
void populateContainer(Container& cont)
{
    int num;

    while (true) {
        cout << "Enter a number (0 to quit): ";
        cin >> num;
        if (num == 0) {
            break;
        }
        cont.push_back(num);
    }
}


// 比较算法
int main(int argc, char const *argv[])
{
    vector<int> myVector;
    list<int> myList;

    cout << "Populate the vector: " << endl;
    populateContainer(myVector);
    cout << "Populate the list: " << endl;
    populateContainer(myList);

    // equal() 和 mismatch() 接收两个范围的首尾迭代器
    if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
        cout << "The two containers have equal elements " << endl;
    } else {
        // 如果两个容器不相等，查找不相同的元素
        auto  miss = mismatch(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList));
        cout << "The following initial elements are the same in "
            << "the vector and the list: " << endl;
        for (auto i = cbegin(myVector); i != miss.first; ++i) {
            cout << *i << '\t';
        }
        cout << endl;
    }

    // 排序
    if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
        cout << "The vector is lexicographically first." << endl;
    } else {
        cout << "The list is lexicographically first." << endl;
    }

    return 0;
}
