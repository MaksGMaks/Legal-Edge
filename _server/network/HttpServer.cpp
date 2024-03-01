#include "HttpServer.hpp"

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <chrono>
#include <thread>
#include <string>
#include <iostream>

namespace net = boost::asio;

void client_session(boost::shared_ptr<net::ip::tcp::socket> sock_ptr);

void HttpServer::test()
{
    typedef boost::shared_ptr<net::ip::tcp::socket> sock_ptr;
    net::io_context ioc{};
    net::ip::tcp::endpoint ep(net::ip::tcp::v4(), 8080);
    net::ip::tcp::acceptor acc(ioc, ep);

    while (1)
    {
        std::cout << "listen, maybe" << std::endl;
        sock_ptr sock(new net::ip::tcp::socket(ioc));
        acc.accept(*sock);
        boost::thread(boost::bind(client_session, sock));
    }
}

void client_session(boost::shared_ptr<net::ip::tcp::socket> sock_ptr)
{
    while (1)
    {
        std::cout << "maybe connect" << std::endl;
        std::string str;
        str.reserve(512);
        size_t len = sock_ptr->read_some(net::buffer(str));
        write(*sock_ptr, net::buffer("ok", 2));
        std::this_thread::sleep_for(std::chrono::seconds(5));
        try
        {
            std::cout << "tryin to close connection" << std::endl;
            sock_ptr->close();
        }
        catch (std::exception &ex)
        {
            std::cout << "exeption" << ex.what() << std::endl;
        }
        break;
    }
}
