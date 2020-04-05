#include <iostream>

#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

auto sum(int a, int b) 
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello CMake!" << std::endl;
    std::cout << CMAKEMACROSAMPLE << std::endl;
    std::cout << "Sum of 3 + 4: " << sum(3, 4) << std::endl;
    return 0;
}
