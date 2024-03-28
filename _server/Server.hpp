#pragma once

#include <memory>

#include "Database/RepositoryManager.hpp"
#include "Database/DatabaseManager.hpp"
#include "Business/BusienessLogic.hpp"
class Server
{
private:
    std::shared_ptr<RepositoryManager> rm;
    std::shared_ptr<DatabaseManager> dbManager;

public:
    Server(std::string db_path, std::string script);
};
