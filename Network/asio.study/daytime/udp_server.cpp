#include <ctime>
#include <iostream>
#include <string>
#include <array>
#include <asio.hpp>

using asio::ip::udp;

std::string make_daytime_string()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

int main(int argc, char const *argv[])
{
    try {
        asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 3333));

        while (true) {
            std::array<char, 1> recv_buf;
            udp::endpoint remote_endpoint;
            asio::error_code error;
            socket.receive_from(asio::buffer(recv_buf), remote_endpoint);

            std::string message = make_daytime_string();

            asio::error_code ignored_error;
            socket.send_to(asio::buffer(message), 
                remote_endpoint, 0, ignored_error);
        }

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}