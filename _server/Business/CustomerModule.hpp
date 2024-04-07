#pragma once

#include "IBusienessModule.hpp"
#include "../Database/RepositoryManager.hpp"

#include <memory>

class CustomerModule : public IBusinessModule
{
public:
    CustomerModule(std::shared_ptr<RepositoryManager> rManager);
    ResponseData executeTask(const RequestData &requestData) override;

private:
    ResponseData createNewCustomer(const Dataset &dataset);
    ResponseData getAllCustomer();

private:
    std::shared_ptr<IRepository> m_customerManager;
};