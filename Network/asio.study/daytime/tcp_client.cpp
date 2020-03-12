#include <iostream>
#include <vector>
#include <asio.hpp>

using asio::ip::tcp;

int main(int argc, char const *argv[])
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        } 
        asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = 
            resolver.resolve(argv[1], "3333");

        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);

        while (true) {
            std::vector<char> buf;
            asio::error_code error;
            size_t len = socket.read_some(asio::buffer(buf), error);

            if (error == asio::error::eof) {
                break;
            } else if(error) {
                throw asio::system_error(error);
            }
            std::cout.write(buf.data(), len);
        }
    } catch(const std::exception& e) {
        std::cerr << "发生了错误" << e.what() << '\n';
    }

    return 0;
}
