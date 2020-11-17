#pragma once

#include <iostream>
#include <functional>

class Task
{
public:
    template<typename Func, typename ...Args>
    Task(Func f, Args ...args)
    {
        func = std::bind(f, std::forward<Args>(args)...);
    }

    void run()
    {
        std::cout << "开始运行任务函数！" << std::endl;
        func();    
        return;
    }

private:
    std::function<void()> func;
};