#include <iostream>
#include "network/HttpServer.cpp"

int main()
{
    const std::string addr{"127.0.0.1"};

    const unsigned short int port = 8080;
    HttpServer server(addr, port);
    std::cout << "after exemple of class" << std::endl;
    // server.run();
    // listen
    // server.test();
    std::cout << "Hello, world" << std::endl;
}