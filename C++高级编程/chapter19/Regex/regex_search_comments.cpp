#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 提取注释

int main(int argc, char const *argv[])
{
    regex r("//\\s*(.+)$");
    while (true) {
        cout << "Enter a string with optional code comments (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q") {
            break;
        }

smatch m;   // 接收匹配的 match_result 对象元素 
if (regex_search(str, m, r)) {
    cout << "Found comment '" << m[1] << "'" << endl;
} else {
    cout << "Invalid date: " << str << endl;
}
    }

    return 0;
}
