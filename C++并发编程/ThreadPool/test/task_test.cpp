#include "../ThreadPool.hpp"
#include <iostream>

void func(int a, int b)
{
    std::cout << a << "+" << b << "=" << a + b << std::endl; 
    return;
}

int main(int argc, char const *argv[])
{
    Task t1(func, 3, 4), t2(func, 5, 6);
    t1.run();
    t2.run();
    
    

    return 0;
}
