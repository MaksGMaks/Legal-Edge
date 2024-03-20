#include <iostream>
#include "network/HttpServer.cpp"
#include "Database/DatabaseManager.hpp"

const std::string ADDR = "127.0.0.1";

int main()
{
    std::string addr = "127.0.0.1";
    DatabaseManager db(DB_PATH, DB_SCRIPT);
    db.start();
    db.selectTest();
    auto server = std::make_unique<HttpServer>(ADDR, 8080);
    std::cout << "Hello, world" << std::endl;
}