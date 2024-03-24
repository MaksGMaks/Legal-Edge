#pragma once

#include "JsonSerializer.hpp"

#include "../Business/BusienessLogic.hpp"
#include "../Database/DatabaseManager.hpp"

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/thread.hpp>

#include <vector>

namespace http = boost::beast::http;

class HttpTransaction
{
public:
    HttpTransaction(boost::shared_ptr<boost::asio::ip::tcp::socket> sock,
                    std::unique_ptr<IDataSerializer> serializer,
                    const std::string &dbPath,
                    const std::string &script);

    void start();

private:
    void do_read();
    void do_response();
    void handle_request();
    void do_close();
    std::vector<std::string> parseApi(const std::string Api);

private:
    const std::string m_dbPath;
    const std::string m_scriptPath;

    boost::beast::tcp_stream m_stream;
    boost::beast::flat_buffer m_buffer;
    // boost::system::error_code m_ec;
    http::response<http::dynamic_body> m_response;
    http::request<http::dynamic_body> m_request;

    std::unique_ptr<IDataSerializer> m_serializer;

    std::shared_ptr<DatabaseManager> m_dbManager;
    std::shared_ptr<RepositoryManager> m_reposManager;
    std::shared_ptr<BusinessLogic> m_blm;
};
