#include "ThreadPool.hpp"
#include <iostream>
#include <mutex>

std::mutex out_mutex;

void func(int a, int b)
{
    std::unique_lock<std::mutex> lock(out_mutex);
    std::cout << a << "+" << b << "=" << a + b << std::endl; 
}

/**
 * 这个运行还是有点问题的，会卡顿，应该是线程退出的问题
 * 不像另外一个线程池，能够很快地运行   
 */ 
int main(int argc, char const *argv[])
{
    std::cout << "测试输出！" << std::endl;
    ThreadPool<> pool(5);
    for (size_t i = 0; i < 1000; i++)
    {
        Task t(func, i, i);
        pool.addOneTask(t);
    }
    pool.print(); 
    return 0;
}
