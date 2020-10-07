#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void findEmptyString(const vector<string>& strings)
{
    auto endIter = end(strings);

    // mem_fn() 调用对象方法指针
    // auto it = find_if(begin(strings), endIter, mem_fn(&string::empty));

    // lambda 表达式
    auto it = find_if(begin(strings), endIter, [](const string& str){ return str.empty(); });

    if (it == endIter) {
        cout << "No empty strings!" << endl;
    } else {
        cout << "Empty string at position: "
            << static_cast<int>(it - begin(strings)) << endl;
    }

}

int main(int argc, char const *argv[])
{
    vector<string> myVector;

    string one = "blah";
    string two = "";

    myVector.push_back(one);
    myVector.push_back(one);
    myVector.push_back(two);
    myVector.push_back(one);

    findEmptyString(myVector);

    return 0;
}
