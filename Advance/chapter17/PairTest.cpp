#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    pair<string, int> myPair("hello", 5);
    pair<string, int> myOtherPair;

    // 直接赋值 first 和 second
    myOtherPair.first = "hello";
    myOtherPair.second = 6;

    // 复制构造
    pair<string, int> myThirdPair(myOtherPair);

    // operator <
    if (myPair < myOtherPair) {
        cout << "myPair is less than myOtherPair" << endl;
    } else {
        cout << "myPair is greater than myOtherPair" << endl;
    }

    // operator==
    if (myOtherPair == myThirdPair) {
        cout << "myOtherPair is equal to myThirdPair" << endl;
    } else {
        cout << "myOtherPair is not equal to myThirdPair" << endl;
    }



    return 0;
}
