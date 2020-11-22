#include "ThreadPool.hpp"
#include <iostream>
#include <mutex>

std::mutex out_mutex;

void func(int a, int b)
{
    std::unique_lock<std::mutex> lock(out_mutex);
    std::cout << a << "+" << b << "=" << a + b << std::endl; 
}

int main(int argc, char const *argv[])
{
    ThreadPool pool(5);
    for (size_t i = 0; i < 100; i++)
    {
        pool.enqueue(func, i, i);
    }

    return 0;
}
