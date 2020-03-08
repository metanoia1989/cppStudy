#include <iostream>
#include <asio.hpp>

void print(const asio::error_code& ec)
{
    std::cout << "错误消息" << std::endl;
}

int main(int argc, char const *argv[])
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.async_wait(&print);

    std::cout << "io.run 之前" << std::endl;

    io.run();

    std::cout << "io.run 之后" << std::endl;

    return 0;
}
