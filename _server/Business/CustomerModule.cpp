#include "CustomerModule.hpp"

#include <iostream>

CustomerModule::CustomerModule(std::shared_ptr<RepositoryManager> rManager)
{
    m_customerManager = std::move(rManager->getCustomerRepository());
    std::cout << "CustomerModule::CustomerModule" << std::endl;
}

ResponseData CustomerModule::executeTask(const RequestData &requestData)
{
    std::cout << "CustomerModule::executeTask" << std::endl;
    ResponseData response;
    if (requestData.submodule == "add" && requestData.method == "POST")
    {
        response = createNewCustomer(requestData.dataset);
    }
    if (requestData.submodule == "get" && requestData.module == "GET")
    {
        response = getAllCustomer();
    }
    return response;
}
ResponseData CustomerModule::createNewCustomer(const Dataset &dataset)
{
    std::cout << "CustomerModule::createNewCustomer" << std::endl;
    ResponseData res;
    return res;
}

ResponseData CustomerModule::getAllCustomer()
{
    ResponseData res;
    std::cout << "CustomerModule::getAllCustomer" << std::endl;
    auto resp = m_customerManager->getAll();
    res.dataset[Keys::Customer::USERNAME] = resp[Database::Customer::USERNAME];
    res.dataset[Keys::Customer::PHONE] = resp[Database::Customer::PHONE];
    return res;
}