#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include "timer.hpp"

std::mutex count_lock;

#define trace(x) { \
    std::scoped_lock<std::mutex> lock(count_lock); \
    std::cout << x << std::endl;  \
}

int main(int argc, char const *argv[])
{
    using namespace std::chrono_literals;

    auto e1 = timer::set_timeout(1s, []{ trace("timeout"); });
    auto e2 = timer::set_timeout(6s, []{ trace("canceled timeout"); });

    auto e3 = timer::set_interval(1s, []{ trace("interval"); });
    auto e4 = timer::set_interval(6s, []{ trace("canceled interval"); });

    trace("waiting 5s");
    std::this_thread::sleep_for(5s);

    e2->signal();
    e4->signal();

    trace("waiting 5s");
    std::this_thread::sleep_for(5s);

    return 1;
}
