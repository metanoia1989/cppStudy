#include <iostream>
#include "Timer.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Timer t = Timer();

    t.setInterval([&](){
        cout << "Hey... After each is..." << endl;
    }, 100);

    t.setTimeout([&](){
        cout << "Hey... After 5.2s. But I will stop the timer!" << endl;
        t.stop();
    }, 5200);

    cout << "I am Timer " << endl;

    while (true); // Keep mail thread active

    return 0;
}
