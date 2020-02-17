#include <iostream>
#include <functional>
#include <string>
#include <vector>

// using std::string;
// using std::vector;
// using std::cout;
// using std::endl;
// using std::reference_wrapper;
// using std::ref;
using namespace std;

int main(int argc, char const *argv[])
{
    string str1 = "Hello";
    string str2 = "World";

    vector<reference_wrapper<string>> vec{ ref(str1) };
    vec.push_back(ref(str2));

    vec[1].get() += "!";

    cout << str1 << " " << str2 << endl;

    return 0;
}
