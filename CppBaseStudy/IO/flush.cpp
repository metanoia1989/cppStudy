#include <iostream>

using namespace std;

int main()
{
    cout << "Hi!" << endl;
    cout << "Hi!" << flush;
    cout << "Hi!" << ends;

    cout << unitbuf;
    cout << "任何缓冲都立即刷新，无缓冲";
    cout << nounitbuf; 
}