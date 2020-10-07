#include <iostream>
#include <functional>
#include <asio.hpp>

class printer
{
public:
    printer() = default;
    ~printer() = default;

    void print(asio::steady_timer *timer, int *count)
    {
        std::cout << "当前值：" << *count << std::endl;
        if (*count < 5) {
            ++*count;
            timer->expires_at(timer->expiry() + std::chrono::seconds(1));
            timer->async_wait(std::bind(&printer::print, this, timer, count));
        }
    }
};


int main(int argc, char const *argv[])
{
    asio::io_context io;

    int count = 0;
    asio::steady_timer t(io, std::chrono::seconds(1));
    printer p;
    t.async_wait(std::bind(&printer::print, &p, &t, &count));

    io.run();

    return 0;
}
