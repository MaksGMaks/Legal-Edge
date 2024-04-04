#include <iostream>
#include <algorithm>

#include <boost/algorithm/string.hpp>

#include "HttpTransaction.hpp"

namespace net = boost::asio;

HttpTransaction::HttpTransaction(boost::shared_ptr<net::ip::tcp::socket> sock,
                                 std::unique_ptr<IDataSerializer> serializer,
                                 std::shared_ptr<DatabaseManager> dbManager) : m_stream(std::move(*sock)),
                                                                               m_reposManager{std::make_shared<RepositoryManager>(dbManager)},
                                                                               m_serializer(std::move(serializer))
{
    m_blm = std::make_shared<BusinessLogic>(m_reposManager);
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
    // Check for valid
    if (m_request.body().size() != 0)
    {
        auto bodyStr = boost::beast::buffers_to_string(m_request.body().data());
        std::cout << "[Transaction ID: {}] SERVER received data: {}" << bodyStr << std::endl;
    }

    // // Prepare RequestData
    RequestData rd;
    std::cout << "before if" << std::endl;
    if (segments.size() >= 3)
    {
        std::cout << "after if" << std::endl;
        auto dataset = m_serializer->deserialize(
            boost::beast::buffers_to_string(m_request.body().data()));

        rd = RequestData{
            .module = segments[Endpoints::Segments::MODULE],
            .submodule = segments[Endpoints::Segments::SUBMODULE],
            .method = m_request.method_string(),
            .resourceId = "",
            .dataset = std::move(dataset)};

        if (segments[Endpoints::Segments::ROOT] != "api")
        {
            std::cout << "[Transaction ID:  ] - HttpSession::handle_request error: Not an API request, expected /api endpoint" << std::endl;
        }

        // if we have resourceId
        if (segments.size() > 3)
        {
            rd.resourceId = segments[Endpoints::Segments::RESOURCE_ID];
        }
    }
    else
    {
        std::cout << "[Transaction ID: {}] - HttpSession::handle_request error: got invalid endpoint format" << std::endl;
    }

    ResponseData *resp;
    auto callback = [resp](ResponseData response)
    {
        *resp = response;
        return response;
    };
    auto response = m_blm->executeTask(rd);
    std::cout << "ssssss" << std::endl;
    // std::cout << resp->dataset.at(Keys::User::USERNAME).front();
    // auto data = m_serializer->deserialize(boost::beast::buffers_to_string(m_request.body().data()));
    // std::string d;
    // for (auto i : data[Keys::User::USERNAME])
    // {
    //     d = {i};
    // }
    // std::cout << "Message - ";
    // std::cout << d << std::endl;
    do_response(response);
}

void HttpTransaction::do_response(const ResponseData &response)
{
    std::string content{"Hello from server!!!"};
    m_response.result(http::status::ok);
    m_response.version(11);

    m_response.set(http::field::server, "MyServer");
    m_response.set(http::field::content_type, "text/plain");
    // m_response.set(http::field::content_length, std::to_string(content.size()));
    Dataset dataset;
    dataset[Keys::User::USERNAME] = {"admin"};
    auto dat = m_serializer->serialize(dataset);
    boost::beast::ostream(m_response.body()) << dat;
    // boost::beast::ostream(m_response.body()) << content;
    // m_response.body()
    //     .insert(m_response.body().end(), content.begin(), content.end());

    http::write(m_stream, m_response);
}

std::vector<std::string> HttpTransaction::parseApi(const std::string endpoint)
{
    std::vector<std::string> segments;
    std::cout << "ENDPOINT -------> " << endpoint << std::endl;
    boost::split(segments, endpoint, boost::is_any_of("/"), boost::token_compress_on);
    segments.erase(std::remove_if(segments.begin(), segments.end(), [](const std::string &s)
                                  { return s.empty(); }),
                   segments.end());

    return segments;
}
