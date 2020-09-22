// g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out

#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <functional>

template<typename Fun, typename Duration, typename ...Args>
auto timer(Fun fun, Duration d, Duration timeout, Args... args)
{
    return std::async(std::launch::async, [=]{
        auto start = std::chrono::system_clock::now();
        while (std::chrono::system_clock::now() - start < timeout) {
            std::this_thread::sleep_for(d);
            std::invoke(fun, args...);
        }
    });
}

int main(int argc, char const *argv[])
{
    using namespace std::chrono_literals;
    timer([]{ std::cout << "echo..."; }, 100ms, 2000ms);
    return 0;
}

