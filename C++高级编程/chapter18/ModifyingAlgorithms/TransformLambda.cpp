#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 转换算法

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
    vector<int> myVector;
    populateContainer(myVector);

    cout << "The vector contains: " << endl;
    for (const auto& i : myVector) { cout << i << " "; }
    cout << endl;

    transform(begin(myVector), end(myVector), begin(myVector), 
        [](int i){ return i + 100; });

    cout << "The vector contains: " << endl;
    for (const auto& i : myVector) { cout << i << " "; }
    cout << endl;

    return 0;
}
