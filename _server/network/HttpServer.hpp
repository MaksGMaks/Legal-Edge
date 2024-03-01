#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace net = boost::asio;

class HttpServer
{
private:
    net::io_context m_ioc;
    net::ip::tcp::acceptor m_acc;
    boost::system::error_code m_ec;
    boost::shared_ptr<net::ip::tcp::socket> m_sock;

private:
    void do_accept();

    void on_accept(boost::system::error_code ec, boost::shared_ptr<net::ip::tcp::socket> sock);

public:
    HttpServer(std::string addr, unsigned short port);

    void run();

    void test();
};
