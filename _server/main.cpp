#include <iostream>
#include "network/HttpServer.cpp"

int main()
{
    HttpServer server;
    // listen
    server.test();
    std::cout << "Hello, world" << std::endl;
}