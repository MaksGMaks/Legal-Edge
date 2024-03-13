#include "HttpServer.cpp"
#include <boost/beast.hpp>

class HttpTransaction
{
private:
    boost::beast::flat_buffer m_buffer;

private:
    void do_read();

public:
};
