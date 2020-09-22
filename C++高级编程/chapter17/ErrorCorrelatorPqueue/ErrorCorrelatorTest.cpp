#include "ErrorCorrelator.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    ErrorCorrelator ec;

    ec.addError(Error(3, "Unable to read file"));
    ec.addError(Error(1, "Incorrect entry from user"));
    ec.addError(Error(10, "Unable to allocate memory!"));

    while (true) {
        try {
            Error e = ec.getError();
            cout << e << endl;
        } catch(const out_of_range& e) {
            cerr << e.what() << '\n';
            break;
        }
        
    }

    return 0;
}
