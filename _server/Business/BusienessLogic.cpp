#include "BusienessLogic.hpp"

#include <iostream>

BusinessLogic::BusinessLogic(/*RepositoryManager &repositoryManager*/) : m_usersModule(std::make_unique<UserModule>(/*repositoryManager*/))
{
    std::cout << "BusinessLogic::BusinessLogic" << std::endl;
}

void BusinessLogic::executeTask(RequestData requestData /*, BusinessLogicCallback callback*/)
{
    std::cout << "BusinessLogic::executeTask()" << std::endl;
    ResponseData responseData;
    try
    {
        if (requestData.module == "users")
        {
            responseData = m_usersModule->executeTask(requestData);
        }
    }
    // catch (const ServerException &ex)
    // {
    //     responseData.dataset[Keys::_ERROR] = {ex.componentName(), ex.what()};
    // }
    catch (const std::exception &ex)
    {
        responseData.dataset[Keys::_ERROR] = {ex.what()};
    }
    catch (...)
    {
        responseData.dataset[Keys::_ERROR] = {"Unreadable exception"};
    }

    // Send response to client
    // callback(responseData);
}