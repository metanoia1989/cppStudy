#include <iostream>
#include <stdexcept>

using namespace std;

void g()
{
    throw invalid_argument("Some exception");
}

void f()
{
    try {
        g();
    } catch(const invalid_argument& e) {
        cerr << "caught in f：" << e.what() << endl;
        throw;
    }
    
}

int main(int argc, char const *argv[])
{
    try {
        f();
    } catch(const std::exception& e) {
        cerr << "caught in main" << e.what() << endl;
    }
    
    return 0;
}
