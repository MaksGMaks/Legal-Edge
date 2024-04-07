#pragma once

#include "IBusienessModule.hpp"
#include "../Database/RepositoryManager.hpp"

#include <memory>

class UserModule : public IBusinessModule
{
public:
    UserModule(std::shared_ptr<RepositoryManager> rManager);
    virtual ResponseData executeTask(const RequestData &requestData) override;

private:
    ResponseData loginUser(const Dataset &dataset);

    ResponseData registerUser(const Dataset &dataset);

private:
    std::shared_ptr<IRepository> m_userRepository;
};