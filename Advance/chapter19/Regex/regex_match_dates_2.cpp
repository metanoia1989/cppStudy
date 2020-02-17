#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 提取输入日期的年月日

int main(int argc, char const *argv[])
{
    regex r("(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])");
    while (true) {
        cout << "Enter a date (year/month/day) (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q") {
            break;
        }

        smatch m;   // 接收匹配的 match_result 对象元素 
        if (regex_match(str, m, r)) {
            int year = stoi(m[1]);
            int month = stoi(m[2]);
            int day = stoi(m[3]);
            cout << "Valid date: Year=" << year 
                << ", month = " << month 
                << ", day=" << day << endl;
        } else {
            cout << "Invalid date: " << str << endl;
        }
    }
    

    return 0;
}
