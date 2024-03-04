#include <iostream>
#include "network/HttpServer.cpp"

int main()
{
    std::string addr = "127.0.0.1";
    HttpServer server(addr, 8080);
    // listen
    // server.test();
    std::cout << "Hello, world" << std::endl;
}