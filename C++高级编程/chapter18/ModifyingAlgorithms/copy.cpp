#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 复制算法 copy()，将源范围内的元素复制到另一个范围。
// 不会向目标范围插入元素，只会改写已有元素。

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


int main(int argc, char const *argv[])
{
    vector<int> vec1, vec2;

    populateContainer(vec1);

    vec2.resize(size(vec1));
    copy(cbegin(vec1), cend(vec1), begin(vec2));

    for (const auto& i : vec2) { cout << i << " "; }

    return 0;
}
