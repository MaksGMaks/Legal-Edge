
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/thread.hpp>

class HttpTransaction
{
public:
    HttpTransaction(boost::shared_ptr<boost::asio::ip::tcp::socket> sock);

private:
    boost::beast::tcp_stream m_stream;
};
