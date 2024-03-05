#include <iostream>

#include <chrono>
#include <thread>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace a = boost::asio;
namespace http = boost::beast::http;

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

    boost::system::error_code ecR;
    boost::beast::tcp_stream stream(std::move(sock));
    boost::beast::flat_buffer buf;
    http::response<http::dynamic_body> m_response;
    http::read(stream, buf, m_response, ecR);

    if (!ecR)
    {
        std::string response_body{boost::beast::buffers_to_string(m_response.body().data())};
        std::cout << response_body << std::endl;
    }
    else
    {
        std::cout << "error in if srtucture" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    sock.close();
    if (!sock.is_open())
    {
        std::cout << "We are disconected" << std::endl;
    }
    std::cout << "Hello, world! (client)" << std::endl;
}