#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 搜索算法

int main(int argc, char const *argv[])
{
    // 列表元素搜索
    vector<int> myVector = { 5, 6, 9, 8, 8, 3 };
    auto beginIter = cbegin(myVector);
    auto endIter = cend(myVector);

    // 搜索不满足谓词的第一个元素 
    auto it = find_if_not(beginIter, endIter, [](int i){ return i < 8;});
    if (it != endIter) {
        cout << "First element not < 8 is " << *it << endl;
    }

    // 找到第一个匹配的连续元素
    it = adjacent_find(beginIter, endIter);
    if (it != endIter) {
        cout << "Found two consecutive equal elements with value " << *it << endl;
    }

    // 找到两个值中的第一个在序列中出现的
    vector<int> targets = { 8, 9 };
    it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));
    if (it != endIter) {
        cout << "Found one of 8 or 9: " << *it << endl;
    }

    // 查找第一个匹配的序列
    vector<int> sub = { 8, 3 };
    it = search(beginIter, endIter, cbegin(sub), cend(sub));
    if (it != endIter) {
        cout << "Found subsequence {8,3} " << endl;
    } else {
        cout << "Unable to find subsequence {8,3}" << endl;
    }

    // 查找最后一个匹配的序列
    auto it2 = find_end(beginIter, endIter, cbegin(sub), cend(sub));
    if (it != it2) {
        cout << "Error: search and find_end found different subsequences "
            << "even though there is only one match." << endl;
    }


    // 查找两个连续8的第一个子序列
    it = search_n(beginIter, endIter, 2, 8);
    if (it != endIter) {
        cout << "Found two consecutive 8s" << endl;
    } else {
        cout << "Unable to find two consecutive 8s" << endl;
    }


    return 0;
}
