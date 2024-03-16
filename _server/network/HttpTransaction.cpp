#include <iostream>
#include <algorithm>

#include <boost/algorithm/string.hpp>

#include "HttpTransaction.hpp"

namespace net = boost::asio;

HttpTransaction::HttpTransaction(boost::shared_ptr<net::ip::tcp::socket> sock, std::unique_ptr<IDataSerializer> serializer) : m_stream(std::move(*sock)), m_serializer(std::move(serializer))
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
    m_buffer.consume(m_buffer.size());

    boost::beast::error_code ec;
    m_request = {};
    http::read(m_stream, m_buffer, m_request, ec);
    if (!ec)
    {
        handle_request();
    }
    else
    {
        std::cout << "Error - " << ec.what() << std::endl;
    }
}

void HttpTransaction::handle_request()
{
    auto segments = parseApi(m_request.target());

    auto data = m_serializer->deserialize(boost::beast::buffers_to_string(m_request.body().data()));
    std::string d;
    for (auto i : data[Keys::User::USERNAME])
    {
        d = {i};
    }
    std::cout << "Message - ";
    std::cout << d << std::endl;
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

std::vector<std::string> HttpTransaction::parseApi(const std::string endpoint)
{
    std::vector<std::string> segments;
    boost::split(segments, endpoint, boost::is_any_of("/"), boost::token_compress_on);
    segments.erase(std::remove_if(segments.begin(), segments.end(), [](const std::string &s)
                                  { return s.empty(); }),
                   segments.end());

    return segments;
}