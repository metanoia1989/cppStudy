#include <iostream>

int main()
{
    using namespace std;
    const int ArrSize = 20;
    char name[ArrSize];
    char dessert[ArrSize];

    cout << "Enter your name: \n";
    // cin.getline(name, ArrSize);
    cin.get(name, ArrSize).get();
    cout << "Enter your favorite dessert: \n";
    // cin.getline(dessert, ArrSize);
    cin.get(dessert, ArrSize).get();
    cout << "I have some dilicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;
}