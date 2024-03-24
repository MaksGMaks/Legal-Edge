#include "Server.hpp"

#include <iostream>

Server::Server(std::string db_path, std::string script) : dbManager{std::make_shared<DatabaseManager>(db_path, script)}
{
    rm = std::make_shared<RepositoryManager>(dbManager);
    std::cout << "Server::Server" << std::endl;
}
