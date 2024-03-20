#include "UserModule.hpp"

#include <iostream>

UserModule::UserModule()
{
    std::cout << "UserModule::UserModule - " << std::endl;
}

ResponseData UserModule::executeTask(const RequestData &requestData)
{
    std::cout << "UserModule::executeTask() - " << std::endl;

    std::cout << std::endl;
    std::cout << "USERNAME ------> " << requestData.dataset.at(Keys::User::USERNAME).front() << std::endl;
    std::cout << "PASSWORD ------> " << requestData.dataset.at(Keys::User::PASSWORD).front() << std::endl;
    std::cout << std::endl;
    ResponseData r;
    return r;
}