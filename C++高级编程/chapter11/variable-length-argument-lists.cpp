#include <cstdio>
#include <cstdarg>
#include <iostream>

using std::cout;

bool debug = false;

void debugOut(const char* str, ...)
{
    va_list ap;
    if (debug) {
        va_start(ap, str);
        vfprintf(stderr, str, ap);
        va_end(ap);
    }
}

void printInts(size_t num, ...)
{
    int temp;
    va_list ap;
    va_start(ap, num);
    for (size_t i = 0; i < num; ++i)
    {
        temp = va_arg(ap, int);
        cout << temp << " ";
    }
    
}