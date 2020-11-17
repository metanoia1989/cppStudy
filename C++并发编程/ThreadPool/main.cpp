#include "ThreadPool.hpp"
#include "Task.hpp"

void func(int a, int b)
{
    std::cout << a << "+" << b << "=" << a + b << std::endl; 
    return;
}

int main(int argc, char const *argv[])
{
    ThreadPool<> pool(5);
    Task t1(func, 3, 4), t2(func, 5, 6);
    
    pool.addOneTask(&t1);
    pool.addOneTask(&t2);

    return 0;
}
