#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> myVector = { 11, 22 };
    myVector.push_back(33);
    myVector.push_back(44);
    cout << "1st element: " << myVector[0] << endl;
    return 0;
}
