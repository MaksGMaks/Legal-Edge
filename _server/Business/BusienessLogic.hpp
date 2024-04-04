#pragma once

#include <functional>
#include <memory>

#include "../dataTypes.hpp"
#include "../Endpoints.hpp"
#include "../Database/RepositoryManager.hpp"

#include "UserModule.hpp"

class RepositoryManager;
class UserModule;

class BusinessLogic
{
public:
    BusinessLogic(const std::shared_ptr<RepositoryManager> &repositoryManager);

    ResponseData executeTask(RequestData requestData);

private:
    std::shared_ptr<UserModule> m_usersModule;
};