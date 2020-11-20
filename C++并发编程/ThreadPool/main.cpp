#include "ThreadPool.hpp"
#include <iostream>

void func(int a, int b)
{
    std::cout << a << "+" << b << "=" << a + b << std::endl; 
    return;
}

/**
 * 这个运行还是有点问题的，会卡顿，应该是线程退出的问题
 * 不像另外一个线程池，能够很快地运行   
 */ 
int main(int argc, char const *argv[])
{
    std::cout << "测试输出！" << std::endl;
    ThreadPool<> pool(5);
    Task t1(func, 3, 4), t2(func, 5, 6);
    
    pool.addOneTask(&t1);
    pool.addOneTask(&t2);

    return 0;
}
