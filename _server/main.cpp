#include <iostream>
#include "network/HttpServer.cpp"

int main()
{
    std::string addr = "127.0.0.1";
    auto server = std::make_unique<HttpServer>(addr, 8080);
    server->run();
    std::cout << "Hello, world" << std::endl;
}