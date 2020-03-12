#include <iostream>
#include <functional>
#include <chrono>
#include <asio.hpp>


void print(const asio::error_code& ec,
    asio::steady_timer *t, int *count)
{ 
    std::cout << *count << std::endl;
    ++(*count);

    t->expires_at(t->expiry() + std::chrono::seconds(1));
    t->async_wait(std::bind(print, std::placeholders::_1, t, count));
}

int main(int argc, char const *argv[])
{
    asio::io_context io;

    int count = 0;
    asio::steady_timer t(io, std::chrono::seconds(1));
    t.async_wait(std::bind(print, std::placeholders::_1, &t, &count));

    io.run();

    std::cout << "Final count is " << count << std::endl;

    return 0;
}
