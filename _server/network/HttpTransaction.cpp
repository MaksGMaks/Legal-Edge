#include <iostream>

#include "HttpTransaction.hpp"

HttpTransaction::HttpTransaction(boost::shared_ptr<boost::asio::ip::tcp::socket> sock) : m_stream(std::move(*sock))
{
    std::cout << "Constructor transaction" << std::endl;
}