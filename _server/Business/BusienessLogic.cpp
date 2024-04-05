#include "BusienessLogic.hpp"

#include <iostream>

BusinessLogic::BusinessLogic(const std::shared_ptr<RepositoryManager> &repositoryManager) : m_usersModule(std::make_shared<UserModule>(repositoryManager)),
                                                                                            m_customerModule(std::make_shared<CustomerModule>(repositoryManager))
{
    std::cout << "BusinessLogic::BusinessLogic" << std::endl;
}

ResponseData BusinessLogic::executeTask(RequestData requestData)
{
    std::cout << "BusinessLogic::executeTask()" << std::endl;
    ResponseData responseData;
    try
    {
        if (requestData.module == "users")
        {
            responseData = m_usersModule->executeTask(requestData);
        }
        if (requestData.module == "customers")
        {
            responseData = m_customerModule->executeTask(requestData);
        }
    }
    // catch (const ServerException &ex)
    // {
    //     responseData.dataset[Keys::_ERROR] = {ex.componentName(), ex.what()};
    // }
    catch (const std::exception &ex)
    {
        std::cout << Keys::_ERROR << ex.what() << std::endl;
        responseData.dataset[Keys::_ERROR] = {ex.what()};
    }
    catch (...)
    {
        std::cout << Keys::_ERROR << "Unreadable exception" << std::endl;
        responseData.dataset[Keys::_ERROR] = {"Unreadable exception"};
    }
    std::cout << "after try???" << std::endl;
    return responseData;
}