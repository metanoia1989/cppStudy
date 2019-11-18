#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    regex r("\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])");
    while (true) {
        cout << "Enter a date (year/month/day) (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q") {
            break;
        }
        if (regex_match(str, r)) {
            cout << "Valid date: " << str << endl;
        } else {
            cout << "Invalid date: " << str << endl;
        }
    }
    

    return 0;
}
