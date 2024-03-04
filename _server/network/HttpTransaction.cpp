#include <iostream>

#include "HttpTransaction.hpp"

namespace net = boost::asio;

HttpTransaction::HttpTransaction(boost::shared_ptr<net::ip::tcp::socket> sock) : m_stream(std::move(*sock))
{
    std::cout << "Constructor transaction" << std::endl;
}

void HttpTransaction::start()
{
    std::cout << "Start" << std::endl;
    do_read();
}

void HttpTransaction::do_read()
{
    std::cout << "heard (in transaction), id -- " << std::this_thread::get_id() << std::endl;

    char data[1024];
    size_t lenght = m_stream.read_some(net::buffer(data), m_ec);

    std::cout << "Message - " << std::string(data, lenght) << std::endl;
}
