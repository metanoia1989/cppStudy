#include <iostream>
#include <asio.hpp>

int main(int argc, char const *argv[])
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.wait();

    std::cout << "5s之后的消息" << std::endl;

    return 0;
}
