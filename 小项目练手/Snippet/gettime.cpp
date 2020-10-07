#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    time_t t = time(nullptr); // get time now
    struct tm *now = localtime(&t);
    cout << (now->tm_year + 1900) << "-" // year
        << (now->tm_mon + 1) << "-" // month
        << now->tm_mday  << " " // day
        << now->tm_hour // hour
        << ":" << now->tm_min // min
        << ":" << now->tm_sec // sec
        << endl; 

    return 0;
}
