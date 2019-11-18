#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char const *argv[])
{
    locale locUSEng("en-US"); // for Windows
    locale locBritEng("en-GB"); // for Windows
    // locale locUSEng("en_US"); // for Linux 
    // locale locBritEng("en_GB"); // for Linux

    wstring dollars = use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol();
    wstring pounds = use_facet<moneypunct<wchar_t>>(locBritEng).curr_symbol();

    wcout << L"In the US, the currency symbol is " << dollars << endl;
    wcout << L"In Great Britain, the currency symbol is " << pounds << endl;

    return 0;
}
