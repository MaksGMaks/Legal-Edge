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
    return response;
}
ResponseData CustomerModule::createNewCustomer(const Dataset &dataset)
{
    std::cout << "CustomerModule::createNewCustomer" << std::endl;
    ResponseData res;

    return res;
}