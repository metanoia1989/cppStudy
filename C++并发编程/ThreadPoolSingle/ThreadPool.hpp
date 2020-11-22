#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <iostream>

class ThreadPool
{
public:
    ThreadPool(size_t);

    ~ThreadPool();

    template<typename Func, typename ...Args>
    auto enqueue(Func&& f, Args&& ...args) 
        -> std::future<typename std::result_of<Func(Args...)>::type>;

private:
    // 工作线程最烈
    std::vector<std::thread> workers;
    // 任务队列
    std::queue<std::function<void()>> tasks;

    // 线程同步
    std::mutex queue_mutex; 
    std::condition_variable condition;
    bool stop;
};

ThreadPool::ThreadPool(size_t threads_num) 
    : stop(false)
{
    for (size_t i = 0; i < threads_num; i++)    
    {
        auto func = [this](){
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(queue_mutex); 
                    condition.wait(lock, [this](){
                        return stop || !tasks.empty();
                    });
                    if (stop && tasks.empty())
                        return;
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        };
        workers.emplace_back(func);
    }
}

ThreadPool::~ThreadPool() 
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    std::cout << tasks.size() << std::endl;
    condition.notify_all();
    for(std::thread& worker : workers)
        worker.join();
}

template<typename Func, typename ...Args>
auto ThreadPool::enqueue(Func&& f, Args&& ...args) 
    -> std::future<typename std::result_of<Func(Args...)>::type>
{
    using return_type = typename std::result_of<Func(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<Func>(f), std::forward<Args>(args)...)
    );
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);    
        // 线程池停止，不允许再添加新的任务
        if (stop)
            throw std::runtime_error("enqueue on stoped ThreadPool");
        tasks.emplace([task](){ (*task)(); });
    }
    condition.notify_one();
    return res;
}