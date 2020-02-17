#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
    for (auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> vectorOne = { 1, 2, 3, 5 };
    vector<int> vectorTwo;

    vectorOne.insert(cbegin(vectorOne)+3, 4);

    for (size_t i = 6; i < 10; i++) {
        vectorTwo.push_back(i);
    }

    printVector(vectorOne);
    printVector(vectorTwo);

    // 将 vectorTwo 所有元素添加到 vector 的结尾
    vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));

    // 删除 2 到 5 的元素
    vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
    printVector(vectorOne);

    vectorTwo.clear();

    vectorTwo.insert(cbegin(vectorTwo), 10, 100);
    vectorTwo.pop_back();
    printVector(vectorTwo);

    return 0;
}
