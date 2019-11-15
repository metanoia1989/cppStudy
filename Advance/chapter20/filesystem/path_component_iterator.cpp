#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main(int argc, char const *argv[])
{
    path p(LR"(C:\Foo\Bar)");
    for (const auto& component : p) {
        cout << component << endl;
    }

    return 0;
}
