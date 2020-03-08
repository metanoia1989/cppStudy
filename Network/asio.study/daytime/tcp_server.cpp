#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>

using asio::ip::tcp;

std::string make_daytime_string()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

int main(int argc, char const *argv[])
{
    try {
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 3333));
        std::cout << "开始监听 3333 端口 " << std::endl;

        while (true) {
            tcp::socket socket(io_context);
            std::cout << "准备接受客户端连接" << std::endl;
            acceptor.accept(socket);

            std::string message = make_daytime_string();

            asio::error_code ignored_error;
            asio::write(socket, asio::buffer(message), ignored_error);
            // asio::write(socket, asio::buffer("hello"), ignored_error);
        }
    } catch(const std::exception& e) {
        std::cerr << "发生了错误" << e.what() << '\n';
    }

    return 0;
}
