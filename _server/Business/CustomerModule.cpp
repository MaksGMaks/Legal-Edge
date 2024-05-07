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
    if (requestData.submodule == "get" && requestData.method == "GET")
    {
        response = getAllCustomers();
    }
    return response;
}
ResponseData CustomerModule::createNewCustomer(const Dataset &dataset)
{
    std::cout << "CustomerModule::createNewCustomer" << std::endl;
    ResponseData res;
    auto username = dataset.at(Keys::Customer::USERNAME).front();
    auto phone = dataset.at(Keys::Customer::PHONE).front();
    m_customerManager->add({username, phone});
    return res;
}

ResponseData CustomerModule::getAllCustomers()
{
    std::cout << "CustomerModule::getAllCustomers" << std::endl;
    ResponseData res;
    auto vec = m_customerManager->getAll();
    res.dataset[Keys::Customer::USERNAME] = vec[Database::Customer::DATABASE_CUSTOMER_USERNAME];
    return res;
}