#include <iostream>
#include "stringbad.h"

using std::cout;
void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("生非贵之所能存，身非爱之所能厚；生亦非贱之所能夭，身亦非轻之所能薄。");
        StringBad headline2("自长非所增，自短非所损。算之所亡若何？");
        StringBad sports("古之人有言，吾尝识之，将以告若。不知所以然而然，命也。");
        cout << "headline1: " << headline1 <<endl;
        cout << "headline2: " << headline2 <<endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 <<endl;
        callme2(headline2);
        cout << "headline2: " << headline2 <<endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot. " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passwd by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passwd by value:\n";
    cout << "   \"" << sb << "\"\n";
}