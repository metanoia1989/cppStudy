#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main(int argc, char const *argv[])
{
    space_info s = space("c:\\");    
    cout << "Capacity: " << s.capacity << endl;
    cout << "Free: " << s.free << endl;

    return 0;
}
