#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const char* s1 = u8R"(Raw UTF-8 encoded string literal)";
    const wchar_t* s2 = LR"(Raw wide string literal)";
    const char16_t* s3 = uR"(Raw char16_t string literal)";
    const char32_t* s4 = UR"(Raw char32_t string literal)";

    cout << s1 << endl;
    wcout << s2 << endl;

    // s3 s4 dont't support output

    const char* formula = u8"\u03C0 r\u00B2";

    return 0;
}
