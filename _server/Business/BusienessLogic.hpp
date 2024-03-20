#pragma once

#include <functional>
#include <memory>

#include "../dataTypes.hpp"
#include "../Endpoints.hpp"

#include "UserModule.hpp"

class RepositoryManager;
class UserModule;

class BusinessLogic
{
public:
    BusinessLogic(/*RepositoryManager &repositoryManager*/);

    void executeTask(RequestData requestData /*, BusinessLogicCallback callback*/);

private:
    std::unique_ptr<UserModule> m_usersModule;
};