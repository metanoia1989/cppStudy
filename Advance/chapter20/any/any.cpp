#include <any>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    any empty;
    any anInt(3);
    any aString("An std::string."s);

    cout << "empty.has_value = " << empty.has_value() << endl;
    cout << "anInt.has_value = " << anInt.has_value() << endl << endl;

    cout << "anInt wrapped type = " << anInt.type().name() << endl;
    cout << "aString wrapped type = " << aString.type().name() << endl << endl;

    int theInt = any_cast<int>(anInt);
    cout << theInt << endl;

    try {
        int test = any_cast<int>(anInt);
        cout << test << endl;
    } catch(const bad_any_cast& e) {
        std::cerr << "Excpetion: " << e.what() << '\n';
    }

    any something(3);
    something = "An std::string."s;

    vector<any> v;
    v.push_back(any(42));
    v.push_back(any("And std::string"s));
    
    cout << any_cast<string>(v[1]) << endl;

    return 0;
}
