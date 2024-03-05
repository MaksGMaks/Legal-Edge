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

    handle_request();
}

void HttpTransaction::handle_request()
{
    do_response();
}

void HttpTransaction::do_response()
{
    std::string content{"Hello from server!!!"};
    m_response.result(http::status::ok);
    m_response.version(11);

    m_response.set(http::field::server, "MyServer");
    m_response.set(http::field::content_type, "text/plain");
    m_response.set(http::field::content_length, std::to_string(content.size()));

    boost::beast::ostream(m_response.body()) << content;
    // m_response.body()
    //     .insert(m_response.body().end(), content.begin(), content.end());

    http::write(m_stream, m_response);
}