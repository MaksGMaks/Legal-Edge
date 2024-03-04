
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/thread.hpp>

class HttpTransaction
{
public:
    HttpTransaction(boost::shared_ptr<boost::asio::ip::tcp::socket> sock);

    void start();

private:
    void do_read();
    void do_response();
    void handle_response();
    void do_close();

private:
    boost::beast::tcp_stream m_stream;
    boost::beast::flat_buffer buffer;
    boost::system::error_code m_ec;
};
