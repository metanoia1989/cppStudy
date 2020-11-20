#pragma once
#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>

class Task
{
public:
    template<typename Func, typename ...Args>
    Task(Func&& f, Args&& ...args)
    {
        func = std::bind(std::forward<Func>(f), std::forward<Args>(args)...);
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

/**
 * 将线程池改成模板类，让任务队列可配置
 */ 
template<typename QueueType = std::queue<Task*>>
class ThreadPool
{
public:
    ThreadPool(size_t n)
    {

        for (int i = 0; i < n; i++) {
            threads.push_back(new std::thread(
                &ThreadPool::thread_worker, this
            ));
        }
    }
    ~ThreadPool()
    {
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        is_running = false; // 线程池即将要销毁停止工作了
    }
        m_cond.notify_all();
        for(auto &worker : threads) {
            worker->join();
            delete worker;
            worker = nullptr;
        }
    }
    
    /**
     * 工作线程入口函数，在取任务和执行任务之间做循环，
     * 直到整个线程池停止工作、被销毁为止   
     */
    void thread_worker()
    {
        while (is_running) {
            Task *t = getOneTask();
            if (t == nullptr) {
                std::cout << "获取任务失败 调用了个寂寞" << std::endl;
                return;
            } else {
                std::cout << "拿到了任务，耶耶耶" << std::endl;
            }
            t->run();
        }
    }
    
    Task *getOneTask()
    {
        {
            // 进入线程临界区时加锁
            std::unique_lock<std::mutex> lock(m_mutex); 
            // 等待任务
            m_cond.wait(lock, [this](){
                return is_running && tasks.empty();
            });
            Task *t = nullptr; 
            if (is_running) {
                t = tasks.front();
                tasks.pop();
            }
            return t;
        }
    }
    
    void addOneTask(Task *t)
    {
        std::unique_lock<std::mutex> lock(m_mutex); 
        // 线程池停止，不允许再添加新的任务
        if (!is_running) { 
            return;
        }
        tasks.push(t);
        std::cout << "添加任务成功！";
        m_cond.notify_one();
    }

private:
    std::vector<std::thread *> threads;
    bool is_running = true;
    QueueType tasks;
    std::mutex  m_mutex;
    std::condition_variable m_cond;
};