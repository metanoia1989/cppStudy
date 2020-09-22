
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 使用容器的erase删除满足特定条件的元素效率低下，使用删除擦除法的复杂度是线性时间
// 算法只能访问迭代器抽象，不能访问容器。删除算法不能真正地从底层容器中删除元素，
// 而是将匹配给定值或谓词的元素替换为下一个不匹配给定值或谓词的元素。
// 使用移动赋值。结果将是范围分为两个集合：一个用于保存要保留的元素，另一个用于保存要删除的元素
// 返回的迭代器指向要删除的元素范围内的第一个元素
// 真真删除容器元素，需要先使用 remove() 算法，然后调用容器的 erase() 方法

// remove 算法 清除容器中的空字符串
void removeEmptyStrings(vector<string>& strings)
{
    auto it = remove_if(begin(strings), end(strings), 
        [](const string& str){ return str.empty(); });
    strings.erase(it, end(strings));
}

// 非算法，删除容器中的空字符串
void removeEmptyStringsWithoutAlgorithms(vector<string>& strings)
{
    for (auto iter = begin(strings); iter != end(strings); ) {
        if (iter->empty()) {
            iter = strings.erase(iter);
        } else {
            ++iter;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<string> myVector = { "", "one", "", "two", "three", "four" };
    for (auto& str : myVector) { cout << "\"" << str << "\" "; }
    cout << endl;
    removeEmptyStrings(myVector);
    for (auto& str : myVector) { cout << "\"" << str << "\" "; }
    cout << endl;

    return 0;
}
