#include <iostream>

#include <chrono>
#include <thread>
#include <boost/asio.hpp>

namespace a = boost::asio;
int main()
{
    a::io_context con{};
    a::ip::tcp::endpoint ep(a::ip::address::from_string("127.0.0.1"), 8080);
    a::ip::tcp::socket sock(con);
    sock.connect(ep);
    if (sock.is_open())
    {
        std::cout << "We are conect" << std::endl;
    }
    std::array<char, 1024> buffer;
    boost::system::error_code ec;
    // size_t bytesread = sock.read_some(a::buffer(buffer), ec);
    // std::cout << std::string(buffer.data(), bytesread) << std::endl;
    std::string hellomessage = {"Hello from client!!!"};
    write(sock, a::buffer(hellomessage + "\n"), ec);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    sock.close();
    if (!sock.is_open())
    {
        std::cout << "We are disconected" << std::endl;
    }
    std::cout << "Hello, world! (client)" << std::endl;
}