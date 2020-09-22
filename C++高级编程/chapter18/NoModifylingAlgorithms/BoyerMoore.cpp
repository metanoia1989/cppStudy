#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

// 专用搜索算法

int main(int argc, char const *argv[])
{
    // C++17 Boyer-Moore 搜索
    string text ="This is the haystack to search a needle in.";
    string toSearchFor = "needle";
    auto searcher = std::boyer_moore_searcher(cbegin(toSearchFor), cend(toSearchFor));
    auto result = search(cbegin(text), cend(text), searcher);
    if (result != cend(text)) {
        cout << "Found the needle." << endl;
    } else {
        cout << "Needle not found." << endl;
    }

    return 0;
}
