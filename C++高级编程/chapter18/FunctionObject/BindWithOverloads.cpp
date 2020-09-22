#include <functional>

using namespace std;

void overloaded(int num) {}
void overloaded(float f) {}

int main(int argc, char const *argv[])
{
    // auto f3 = bind(overloaded, placeholders::_1);
    auto f4 = bind((void(*)(float))overloaded, placeholders::_1);

    return 0;
}
