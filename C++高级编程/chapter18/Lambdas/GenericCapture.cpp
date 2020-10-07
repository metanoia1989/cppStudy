#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    {
        double pi = 3.1415;
        auto myLambda = [myCapture = "Pi: ", pi]{ cout << myCapture << pi << endl; };
        myLambda();
    }

    {
        auto myPtr = std::make_unique<double>(3.1415);
        auto myLambda = [p = std::move(myPtr)]{ cout << *p << endl; };
        myLambda();
    }
     
    {
        auto myPtr = std::make_unique<double>(3.1415);
        auto myLambda = [myPtr = std::move(myPtr)]{ cout << *myPtr << endl; };
        myLambda();
    }

    return 0;
}
