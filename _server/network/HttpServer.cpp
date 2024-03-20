#include "HttpServer.hpp"

#include <winsock2.h>
#include <ws2tcpip.h>

#include <chrono>
#include <string>

#define MAX_THREADS (std::thread::hardware_concurrency()) * 2

HttpServer::HttpServer(std::string addr, unsigned short port) : m_ioc{1},
                                                                m_acc{m_ioc, net::ip::tcp::endpoint(net::ip::make_address(addr), static_cast<net::ip::port_type>(port))},
                                                                m_thrpool{std::make_unique<ThreadPool>(MAX_THREADS)}
{
    std::cout << "constructor HttpSession" << std::endl;
    try
    {
        do_accept();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void HttpServer::run()
{
    m_ioc.run();
}

void HttpServer::do_accept()
{
    std::cout << "listen ..." << std::endl;
    m_sock = boost::make_shared<net::ip::tcp::socket>(m_ioc);
    m_acc.accept(*m_sock);
    std::cout << "connecting" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // idk, but this connection doesent work at 2nd connection from client
    m_thrpool->enqueue([this]
                       { on_accept(std::move(m_ec), std::move(m_sock)); });
    std::cout << "after calling method on_accept into threadpool, id -- " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    do_accept();
}

void HttpServer::on_accept(boost::system::error_code ec, boost::shared_ptr<net::ip::tcp::socket> sock)
{

    std::cout << "heard, id -- " << std::this_thread::get_id() << std::endl;

    auto t = std::make_shared<HttpTransaction>(std::move(sock), std::make_unique<JsonSerializer>());
    t->start();
}