#pragma once

#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>
#include <memory>
#include <utility>

class Task
{
public:
    Task() {};

    template<typename Func, typename ...Args>
    Task(Func f, Args&& ...args)
    {
        func = std::bind(f, std::forward<Args>(args)...);
    }

    void run()
    {
        func();    
        return;
    }

private:
    std::function<void()> func;
};

/**
 * 将线程池改成模板类，让任务队列可配置
 */ 
template<typename QueueType = std::queue<Task>>
class ThreadPool
{
public:
    ThreadPool(size_t n);

    ~ThreadPool();
    
    void addOneTask(Task& t);
    
    void print()
    {
        std::cout << "task length: " << tasks.size() << std::endl;    
    }

private:
    std::vector<std::thread> threads;
    bool is_running = true;
    QueueType tasks;
    std::mutex  m_mutex;
    std::condition_variable m_cond;
};

template<typename QueueType> 
ThreadPool<QueueType>::ThreadPool(size_t threads_num) 
{
    for (int i = 0; i < threads_num; i++) {
        auto func = [this](){
            while (true) {
                Task t; 
                {
                    // 进入线程临界区时加锁
                    std::unique_lock<std::mutex> lock(m_mutex); 
                    // 等待任务
                    m_cond.wait(lock, [this](){
                        return !is_running || !tasks.empty();
                    });
                    if (!is_running && tasks.empty()) {
                        return;
                    }
                    t = std::move(tasks.front());
                    tasks.pop();
                }
                t.run();
            }
        };
        threads.emplace_back(func);
    }
}

template<typename QueueType>
ThreadPool<QueueType>::~ThreadPool() 
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        is_running = false; // 线程池即将要销毁停止工作了
    }
    print();
    m_cond.notify_all();
    for(auto &thread : threads) {
        thread.join();
    }
}

template<typename QueueType>
void ThreadPool<QueueType>::addOneTask(Task& t) 
{
    std::unique_lock<std::mutex> lock(m_mutex); 
    // 线程池停止，不允许再添加新的任务
    if (!is_running) { 
        return;
    }
    tasks.push(std::move(t));
    m_cond.notify_one();
}