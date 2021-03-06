#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main(int argc, char const *argv[])
{
    regex reg(R"([\w]+)");
    while (true) {
        cout << "Enter a string to split (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q") {
            break;
        }

const sregex_iterator end;
for (sregex_iterator iter(cbegin(str), cend(str), reg); iter != end; ++iter) {
    cout << "\"" << (*iter)[0] << "\"" << endl;
}


    }
    

    return 0;
}
