#include <iostream>
#include "network/HttpServer.cpp"
#include "Server.hpp"

const std::string ADDR = "127.0.0.1";

int main()
{
    auto server = std::make_unique<HttpServer>(ADDR, 8080, DB_PATH, DB_SCRIPT);
    // RepositoryManager rm(std::make_shared<DatabaseManager>(DB_PATH, DB_SCRIPT));
    std::cout << "Hello, world" << std::endl;
}